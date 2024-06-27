from gtts import gTTS
import vlc
import time
import speech_recognition as sr
import webbrowser
from datetime import datetime
from datetime import date
import pyautogui
from time import sleep


def voice(responce,sleep_time):
        x= gTTS(
            text= responce,lang='en',slow=False
        )
        x.save("welcome.mp4")
        p=vlc.MediaPlayer("./welcome.mp4")
        p.play()
        while True:
            pass
            time.sleep(int(sleep_time))
            break
response= 'Welcome How can I help you ?'
voice(response,3)        

def get_voice_command():
    recognizer = sr.Recognizer()
    with sr.Microphone() as source:
        print("Listening for your command...")
        audio = recognizer.listen(source)
        try:
            command = recognizer.recognize_google(audio)
            print(f"You said: {command}")
            return command.lower()
        except sr.UnknownValueError:
            responce= "Sorry, I could not understand your command."
            voice(responce,3)
            return ""
        except sr.RequestError:
            print("Could not request results from Google Speech Recognition service.")
            return ""

def tell_time():
    now = datetime.now()
    current_time = now.strftime("%H:%M:%S")
    return current_time


def main():
    
    while True:
        command = get_voice_command()

        if 'time' in command:
            current_time = tell_time()
            response = f"The current time is {current_time}."
            voice(response,5)

        elif 'google' in command:
            webbrowser.open("https://www.google.com")
            response = "Opening Google."
            voice(response,2)
            sleep(2)
            command = get_voice_command()
            while 'search'in command:
                command=command.split()
                command.remove('search')
                command.remove('for')
                command= " ".join(command)
                pyautogui.typewrite(command)
                sleep(2)
                pyautogui.hotkey("Enter")
                break
                
        elif 'matches today' in command:
            today = date.today()
            today= str(today).split("-")
            today=today[::-1]
            today=f"{today[1]}/{today[0]}/{today[2]}"
            print(today)
            webbrowser.open(f"https://www.yallakora.com/match-center/%D9%85%D8%B1%D9%83%D8%B2-%D8%A7%D9%84%D9%85%D8%A8%D8%A7%D8%B1%D9%8A%D8%A7%D8%AA?date={today}#")
            response = "Today matches"
            voice(response,2)
            
            
        elif 'WhatsApp'in command:
            try:
                location=None
                while location is None:
                    location=pyautogui.locateOnScreen('what\'s.png')
                    sleep(1)
                pyautogui.click(location.left,location.top)
            except pyautogui.ImageNotFoundException:
                print("not found") 
                
                
        elif 'exit' in command:
            response = "I hope I have helped you, thank you for using me "
            voice(response,4)

            break

        else:
            response = "I did not understand that command."
            x= gTTS(
            text= response,lang='en',slow=False
            )   
            x.save("welcome.mp4")
            p=vlc.MediaPlayer("./welcome.mp4")
            p.play()
            while True:
                pass
                time.sleep(5)
                break


if __name__ == "__main__":
    main()