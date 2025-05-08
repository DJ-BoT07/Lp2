def evaluate_employee():
    name = input("Name: ")
    productivity = int(input("Productivity (0-10): "))
    quality = int(input("Quality of Work (0-10): "))
    teamwork = int(input("Teamwork (0-10): "))
    attendance = int(input("Attendance (0-10): "))

    weights = {"Productivity": 0.3, "Quality": 0.3, "Teamwork": 0.2, "Attendance": 0.2}
    score = (
        productivity * weights["Productivity"] +
        quality * weights["Quality"] +
        teamwork * weights["Teamwork"] +
        attendance * weights["Attendance"]
    )

    if score >= 8:
        category = "Excellent"
    elif score >= 6:
        category = "Good"
    elif score >= 4:
        category = "Average"
    else:
        category = "Needs Improvement"

    print(f"✅ {name} evaluated! Score: {round(score, 2)} / 10, Category: {category}")
    return {"name": name, "productivity": productivity, "quality": quality, "teamwork": teamwork, "attendance": attendance, "score": score, "category": category}

evaluations = []

def show_all_evaluations():
    if not evaluations:
        print("\nNo evaluations yet.")
    else:
        print("\nAll Evaluations:")
        for eval in evaluations:
            print(f"Name: {eval['name']}, Score: {round(eval['score'], 2)}, Category: {eval['category']}")

def main():
    while True:
        print("\n1. Evaluate Employee")
        print("2. Show All Evaluations")
        print("3. Exit")
        choice = input("Choose an option (1/2/3): ")
        if choice == '1':
            evaluation = evaluate_employee()
            evaluations.append(evaluation)
        elif choice == '2':
            show_all_evaluations()
        elif choice == '3':
            break
        else:
            print("Invalid choice.")

main()
