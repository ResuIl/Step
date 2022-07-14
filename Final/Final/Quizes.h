#pragma once

class Quizes {
    string _quiz;
    string _correctAnswer;
    vector<string> answers;
public:

    Quizes(string quiz) : _quiz(quiz) {}

    void setCorrectAnswer(string correctAnswer) {
        _correctAnswer = correctAnswer;
    }

    void addAnswer(string answer) {
        answers.push_back(answer);
    }

    string getQuiz() {
        return _quiz;
    }

    vector<string> getAnswers() {
        return answers;
    }

    bool isAnswerCorrect(string answer) {
        return _correctAnswer == answer;
    }

};
