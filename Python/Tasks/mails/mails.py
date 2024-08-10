def process_mails(input_filename, output_filename):
    try:
        # Open the input file in read mode
        with open(input_filename, 'r') as infile:
            lines = infile.readlines()

        emails = []
        count = 0

        for line in lines:
            # Check if the line starts with 'From '
            if line.startswith('From '):
                parts = line.split()
                if len(parts) > 1:
                    emails.append(parts[1])
                    count += 1

        # Write the output to the output file
        with open(output_filename, 'w') as outfile:
            for email in emails:
                outfile.write(email + '\n')
            outfile.write(f'\nCount of mails sent: {count}\n')

        # Print the emails and the count
        for email in emails:
            print(email)
        print(f'\nCount of mails sent: {count}\n')

    except FileNotFoundError:
        print(f'The file {input_filename} does not exist.')


process_mails('mails.txt', 'mails_output.txt')
