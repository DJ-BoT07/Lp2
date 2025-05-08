import streamlit as st
import matplotlib.pyplot as plt
import mysql.connector
import pandas as pd

# MySQL DB connection setup
conn = mysql.connector.connect(
    host="localhost",
    user="root",
    password="9423260212",
    database="employee_db"
)
cursor = conn.cursor()

# Create table if not exists
cursor.execute("""
    CREATE TABLE IF NOT EXISTS evaluations (
        id INT AUTO_INCREMENT PRIMARY KEY,
        name VARCHAR(255),
        productivity INT,
        quality INT,
        teamwork INT,
        attendance INT,
        score FLOAT,
        category VARCHAR(50)
    )
""")

# Title
st.title("Simple Employee Evaluation")

# Sidebar Inputs
st.sidebar.header("Enter Employee Details")
name = st.sidebar.text_input("Name")
productivity = st.sidebar.slider("Productivity", 0, 10, 5)
quality = st.sidebar.slider("Quality of Work", 0, 10, 5)
teamwork = st.sidebar.slider("Teamwork", 0, 10, 5)
attendance = st.sidebar.slider("Attendance", 0, 10, 5)

# Evaluation Button
if st.sidebar.button("Evaluate"):
    # Weights
    weights = {"Productivity": 0.3, "Quality": 0.3, "Teamwork": 0.2, "Attendance": 0.2}
    score = (
        productivity * weights["Productivity"] +
        quality * weights["Quality"] +
        teamwork * weights["Teamwork"] +
        attendance * weights["Attendance"]
    )

    # Classification
    if score >= 8:
        category = "Excellent"
    elif score >= 6:
        category = "Good"
    elif score >= 4:
        category = "Average"
    else:
        category = "Needs Improvement"

    # Save to DB
    cursor.execute("""
        INSERT INTO evaluations (name, productivity, quality, teamwork, attendance, score, category)
        VALUES (%s, %s, %s, %s, %s, %s, %s)
    """, (name, productivity, quality, teamwork, attendance, score, category))
    conn.commit()

    # Results
    st.subheader("Evaluation Results")
    st.write(f"**Name:** {name}")
    st.write(f"**Score:** {round(score, 2)} / 10")
    st.write(f"**Performance:** {category}")

    # Chart
    st.subheader("Performance Chart")
    criteria = ["Productivity", "Quality", "Teamwork", "Attendance"]
    scores = [productivity, quality, teamwork, attendance]
    
    fig, ax = plt.subplots()
    ax.bar(criteria, scores, color="skyblue")
    ax.set_ylim(0, 10)
    ax.set_ylabel("Score")
    ax.set_title("Performance Breakdown")
    st.pyplot(fig)

# Button to show all evaluations
if st.button("Show All Evaluations"):
    cursor.execute("SELECT * FROM evaluations")
    results = cursor.fetchall()
    df = pd.DataFrame(results, columns=['ID', 'Name', 'Productivity', 'Quality', 'Teamwork', 'Attendance', 'Score', 'Category'])
    st.dataframe(df)

# Footer
st.markdown("---")
st.caption("Built with ❤️ using Streamlit")

# Close DB connection on app exit
