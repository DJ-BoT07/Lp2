
def display_menu():
    print("\n=== Hospital Expert System ===")
    print("1. Add New Patient")
    print("2. Update Patient Symptoms")
    print("3. Diagnose Patient")
    print("4. View Patient Records")
    print("5. View Diagnosis History")
    print("6. Quit")

# Global list to store patients
patients = []

# Simple rule-based knowledge base
rules = {
    ("fever", "cough", "fatigue"): ("Flu", "Rest, fluids, and paracetamol"),
    ("fever", "cough", "breathlessness"): ("COVID-19", "Isolation, PCR test, and monitoring"),
    ("headache", "blurred vision"): ("Migraine", "Pain relief, rest in a dark room"),
    ("chest pain", "shortness of breath"): ("Heart Attack", "Emergency treatment"),
    ("sore throat", "fever"): ("Tonsillitis", "Warm fluids, rest, and medication"),
    ("joint pain", "swelling"): ("Arthritis", "Painkillers and physical therapy"),
    ("nausea", "vomiting", "diarrhea"): ("Food Poisoning", "Hydration and light diet"),
    ("rash", "itching"): ("Allergy", "Antihistamines and avoiding allergens"),
    ("fever", "headache", "muscle pain"): ("Dengue", "Fluids, rest, and medical observation")
}

def add_patient():
    print("\n--- Add New Patient ---")
    name = input("Name: ")
    age = input("Age: ")
    gender = input("Gender: ")
    address = input("Address: ")
    symptoms = input("Enter symptoms (comma separated): ").lower().split(',')
    symptoms = [s.strip() for s in symptoms]

    patient = {
        'name': name,
        'age': age,
        'gender': gender,
        'address': address,
        'symptoms': symptoms,
        'diagnosis': None,
        'treatment': None,
        'history': []
    }
    patients.append(patient)
    print("Patient added successfully.")

def update_patient_symptoms():
    name = input("\nEnter patient name to update symptoms: ")
    for patient in patients:
        if patient['name'].lower() == name.lower():
            symptoms = input("Enter updated symptoms (comma separated): ").lower().split(',')
            patient['symptoms'] = [s.strip() for s in symptoms]
            print("Symptoms updated.")
            return
    print("Patient not found.")

def diagnose_patient():
    name = input("\nEnter patient name to diagnose: ")
    for patient in patients:
        if patient['name'].lower() == name.lower():
            symptoms_set = set(patient['symptoms'])
            for rule_symptoms, (diagnosis, treatment) in rules.items():
                if set(rule_symptoms).issubset(symptoms_set):
                    patient['diagnosis'] = diagnosis
                    patient['treatment'] = treatment
                    patient['history'].append((diagnosis, treatment))
                    print(f"Diagnosis: {diagnosis}")
                    print(f"Recommended Treatment: {treatment}")
                    return
            patient['diagnosis'] = "Unknown"
            patient['treatment'] = "Consult a specialist"
            patient['history'].append(("Unknown", "Consult a specialist"))
            print("No clear match. Please consult a doctor.")
            return
    print("Patient not found.")

def view_patients():
    print("\n--- All Patient Records ---")
    if not patients:
        print("No records.")
        return
    for i, p in enumerate(patients, start=1):
        print(f"\nPatient {i}")
        print(f"Name: {p['name']}")
        print(f"Age: {p['age']}")
        print(f"Gender: {p['gender']}")
        print(f"Address: {p['address']}")
        print(f"Symptoms: {', '.join(p['symptoms'])}")
        print(f"Diagnosis: {p['diagnosis'] or 'Not diagnosed'}")
        print(f"Treatment: {p['treatment'] or 'Not prescribed'}")

def view_diagnosis_history():
    name = input("\nEnter patient name to view diagnosis history: ")
    for patient in patients:
        if patient['name'].lower() == name.lower():
            print(f"\nDiagnosis History for {patient['name']}:")
            if not patient['history']:
                print("No diagnosis history.")
            else:
                for i, (d, t) in enumerate(patient['history'], start=1):
                    print(f"{i}. Diagnosis: {d} | Treatment: {t}")
            return
    print("Patient not found.")

# Main menu loop
while True:
    display_menu()
    choice = input("Choose an option: ")

    if choice == '1':
        add_patient()
    elif choice == '2':
        update_patient_symptoms()
    elif choice == '3':
        diagnose_patient()
    elif choice == '4':
        view_patients()
    elif choice == '5':
        view_diagnosis_history()
    elif choice == '6':
        break
    else:
        print("Invalid choice. Try again.")

print("\nThank you for using the Hospital Expert System!")
