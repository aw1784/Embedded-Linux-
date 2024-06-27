"""
This code for importing today matches from yallakora by using BeautifulSoup

"""
from datetime import date
import requests
from bs4 import BeautifulSoup
today = date.today()
today= str(today).split("-")
today=today[::-1]
today=f"{today[1]}/{today[0]}/{today[2]}"
page =requests.get(f"https://www.yallakora.com/match-center/%D9%85%D8%B1%D9%83%D8%B2-\
    %D8%A7%D9%84%D9%85%D8%A8%D8%A7%D8%B1%D9%8A%D8%A7%D8%AA?date={today}#")
def main(page):
    src= page.content # Return the content code as byte code
    soup= BeautifulSoup(src,"lxml") # "lxml" is the parsing that will change the byte code to a code so i can understand it
    # NOTE you don't have to use lxml but we use it as it is recommended for speed
    match_details=[]
    championships =soup.find_all("div",{"class":'matchCard'})
    def get_match_info(championships):
        championship_title= championships.contents[1].find("h2").text.strip()
        print(championship_title.center(100))
        divteamA=championships.find_all("div",{"class":'teamA'})
        divteams_Score=championships.find_all("span",{"class":'score'})
        divteams_Time=championships.find_all("span",{"class":'time'})
        divteamB=championships.find_all("div",{"class":'teamB'})
        num_of_matches=0
        counter=0
        teamsA=[]
        teamsA_score=[]
        teamsB=[]
        teamsB_score=[]
        match_time=[]
        
        while len(divteamA)>num_of_matches :
            teamsA.append(divteamA[num_of_matches].text.strip())
            match_time.append(divteams_Time[num_of_matches].text.strip())
            teamsA_score.append(divteams_Score[counter].text.strip())
            counter+=2
            num_of_matches+=1
        
        num_of_matches=0
        counter=1
        while len(divteamB)>num_of_matches :
            teamsB.append(divteamB[num_of_matches].text.strip())
            teamsB_score.append(divteams_Score[counter].text.strip())
            counter+=2
            num_of_matches+=1
        
        for i in range(num_of_matches):
            print(f"{teamsA[i]}  {teamsA_score[i]} - {teamsB_score[i]} {teamsB[i]}                  {match_time[i]}".center(50),)
    for x in range(len(championships)):
        get_match_info(championships[x])
    
main(page)