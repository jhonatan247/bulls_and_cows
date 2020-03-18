#include <bits/stdc++.h>

using namespace std;

struct Question
{
    pair<pair<short,short>,pair<short,short> > number;
    short bulls;
    short cows;
    short step;
};

bool mainMenu()
{
    cout<<"Main Menu"<<endl;
    cout<<"Input 1 to start"<<endl;
    cout<<"Input other to exit"<<endl;
    string input;
    cin >> input;
    return input == "1";
}

void printQuestionNumber(Question question)
{
    cout<<question.number.first.first<<question.number.first.second<<question.number.second.first<<question.number.second.second<<endl;
}

Question askQuestion(Question question)
{
    short bulls, cows;
    cout<<"Input the number of bulls of the number bellow ";
    printQuestionNumber(question);
    cin>>bulls;
    cout<<"Input the number of cows of the number bellow ";
    printQuestionNumber(question);
    cin>>cows;
}

short getValueOfQuestion(Question question)
{
    return question.bulls + question.cows;
}

Question createQuestion(short a, short b, short c, short d, short step)
{
    Question newQuestion;
    newQuestion.number.first.first = 9;
    newQuestion.number.first.second = 8;
    newQuestion.number.second.first = 7;
    newQuestion.number.second.second = 6;
    newQuestion.step = step;
    return newQuestion;
}

short getCountOfQuestionsInCurrentStep(vector<Question> askedQuestions)
{
    Question lastQuestion = askedQuestions[askedQuestions.size() - 1];
    short currentStep = lastQuestion.step;
    short countOfQuestions = 0;
    for(int i = askedQuestions.size() - 1; i>= 0; i--)
    {
        if(askedQuestions[i].step == currentStep)
        {
            countOfQuestions++;
        }
        else
        {
            break;
        }
    }
    return countOfQuestions;
}


vector<Question> getNextQuestions(vector<Question> askedQuestions)
{
    vector<Question> nextQuestions;

    Question lastQuestion = askedQuestions[askedQuestions.size() - 1];
    short valueOfLastQuestion = getValueOfQuestion(lastQuestion);
    short currentStep = lastQuestion.step;
    short countInCurrentStep = getCountOfQuestionsInCurrentStep(askedQuestions);

    if(valueOfLastQuestion == 4)
    {
        return nextQuestions;
    }
    switch(currentStep)
    {
        case 1:
            switch(countInCurrentStep){
                case 1:
                    nextQuestions.push_back(createQuestion(5, 4, 3, 2, 1));
                    break;
                case 2:
                    Question firstQuestion = askedQuestions[askedQuestions.size() - 2];
                    short valueOfFirstQuestion = getValueOfQuestion(firstQuestion);
                    if(valueOfFirstQuestion + valueOfLastQuestion == 4){

                    }else if(valueOfFirstQuestion == 0){

                    } else if(valueOfLastQuestion == 0){

                    } else {

                    }
                    break;
                case 3:
                    break;
                case 4:
                    break;
            }
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
    }
    return nextQuestions;
}

void agent()
{
    vector<Question> askedQuestions;
    queue<Question> questionQueue;
    Question firstQuestion = createQuestion(9, 8, 7, 6, 1);
    questionQueue.push(firstQuestion);
    while(!questionQueue.empty())
    {
        Question currentQuestion = questionQueue.front();
        questionQueue.pop();
        currentQuestion = askQuestion(currentQuestion);
        askedQuestions.push_back(currentQuestion);
        vector<Question> nextQuestions = getNextQuestions(askedQuestions);
        for(int i = 0; i < nextQuestions.size(); i++){
            questionQueue.push(nextQuestions[i]);
        }
    }


}

int main()
{
    while(mainMenu())
    {
        agent();
    }
    return 0;
}
