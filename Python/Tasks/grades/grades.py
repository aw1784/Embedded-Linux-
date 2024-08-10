def process_grades(input_filename, output_filename):
    try:
        # Open the input file in read mode
        with open(input_filename, 'r') as infile:
            lines = infile.readlines()

        students = {}
        for line in lines:
            parts = line.strip().split(',')
            name = parts[0]
            if len(parts) > 1:
                try:
                    grades = list(map(float, parts[1:]))
                    if len(grades) > 0:
                        average = sum(grades) / len(grades)
                        students[name] = (grades, average)
                except ValueError:
                    # Handle case where conversion to float fails
                    print(f"Skipping line due to conversion error: {line.strip()}")
            else:
                # Handle case where there are no grades
                print(f"Skipping line with no grades: {line.strip()}")

        if not students:
            print("No valid student data found.")
            return

        # Identify the top student
        top_student = max(students.items(), key=lambda item: item[1][1])

        # Write the output to the output file
        with open(output_filename, 'w') as outfile:
            for name, (grades, average) in students.items():
                outfile.write(f'{name}: Grades = {grades}, Average = {average:.2f}\n')
            outfile.write(f'\nTop Student: {top_student[0]} with an average grade of {top_student[1][1]:.2f}\n')


        for name, (grades, average) in students.items():
            print(f'{name}: Grades = {grades}, Average = {average:.2f}')
        print(f'\nTop Student: {top_student[0]} with an average grade of {top_student[1][1]:.2f}\n')

    except FileNotFoundError:
        print(f'The file {input_filename} does not exist.')
    except Exception as e:
        print(f'An error occurred: {e}')


process_grades('input.txt', 'output.txt')
