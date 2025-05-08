from nltk.chat.util import Chat, reflections
from datetime import date, datetime
import re

pairs = [
    [
        r".*(My Name is (.*))",
        ["Hello %1, How are you today ?", "Nice to meet you"]
    ],
    [
        r".*(What is your name).*",
        ["I am chatbot created by DJ", "I am a chatbot"]
    ],
    [
        r".*(your name).*",
        ["I am a chatbot created by DJ", "I am a chatbot"]
    ],
    [
        r".*(How are you).*",
        ["I am fine", "I am always happy to help"]
    ],
    [
        r".*(Hi|Hello|Hey).*",
        ["Hey there", "hello"]
    ],
    [
        r".*(company).*",
        ["Amazon", "Tesla"]
    ],
    [
        r".*(today date|date today|current date).*",
        [lambda: f"Today is {date.today()} and the current time is {datetime.now().strftime('%H:%M:%S')}"]
    ]
]

def chat():
    print("Hello I am a chatbot. Type 'quit' to exit")
    
    while True:
        user_input = input("> ").lower()
        if user_input == 'quit':
            break
            
        chat_bot = Chat(pairs, reflections)
        response = chat_bot.respond(user_input)
        
        print(response or "I'm not sure how to respond to that.")

if __name__ == "__main__":
    chat()