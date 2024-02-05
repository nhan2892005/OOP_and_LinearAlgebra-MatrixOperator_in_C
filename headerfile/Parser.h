#ifndef Parser_h
#define Parser_h

#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <cstdlib>
#include <cstring>


class Expression
{
    private:
        std::string statement;
        std::vector<std::pair<char,int>> character;
        std::vector<std::string> Tokens;
        std::vector<std::string> Variable;
        std::set<char> op = {'^','+','-','*','/','(',')','~'};
        //
        std::stack<Matrix> Calculation;
        // stack to process the expression
        int priority(char c){
            switch (c)
            {
            case '^':
                return 1;
                break;
            case '/':
            case '*':
                return 2;
                break;
            case '+':
            case '-':
                return 3;
                break;
            case '(':
            case ')':
                return 4;
                break;
            default:
                return 5;
                break;
            }
        }
    public:
        Expression (std::string line)
            :statement(line)
        {
            separate();
        }

        ~Expression ()
        {
        }

        void Process_operator(char c){
            // if it's the end statment, then print all in vector from back to front
            if (c == '~'){
                while (!character.empty()){
                    Tokens.push_back(std::string(1, character.back().first));
                    character.pop_back();
                }
                return;
            }
            //if character is empty or priority of c is less than the last character in vector
            if (c == '('){
                character.push_back(std::make_pair(c, priority(c)));
            } else if (c == ')'){
                while (character.back().first != '('){
                    Tokens.push_back(std::string(1, character.back().first));
                    character.pop_back();
                    if ( character.empty() ){
                        std::cout << "Error: No matching '(' " << std::endl;
                        return;
                    }
                }
                character.pop_back();
            }else if (character.empty() || priority(c) < character.back().second){
                character.push_back(std::make_pair(c, priority(c)));
            }else{
                while (!character.empty() && priority(c) >= character.back().second){
                    Tokens.push_back(std::string(1, character.back().first));
                    character.pop_back();
                }
                character.push_back(std::make_pair(c, priority(c)));
            }
        }

        void Process_Variable(string tmp){
            if (isalpha(tmp[0]) && !(std::find(Variable.begin(), Variable.end(), tmp) != Variable.end())){
                Variable.push_back(tmp);
            }
        }
        bool checkVar(unordered_map<string, int> MatrixName){
            for (const auto tmp : Variable){
                auto it = MatrixName.find(tmp);
                if (it == MatrixName.end()) 
                    return false;
            }
            return true;
        }
        void separate(){
            std::string tmp = "";
            for (const char c : statement){
                if (c == char(32)){
                    continue;
                } 
                if (op.find(c) == op.end() || tmp=="{"){
                    tmp += c;
                }else {
                    if (tmp != ""){
                        Tokens.push_back(tmp);
                        Process_Variable(tmp);
                        tmp = "";
                    }
                    Process_operator(c);
                }
            }
        }
        bool isNumber(std::string s){
            char* endptr; 
            std::strtod(s.c_str(), &endptr);
            return !s.empty() && *endptr == '\0';
        }
        bool isVariable(std::string s){
            if (std::find(Variable.begin(), Variable.end(), s) != Variable.end()){
                return true;
            }
            return false;
        }

        bool isOperator(std::string s){
            if (s.size() > 1){
                return false;
            }
            if (op.find(s[0]) != op.end()){
                return true;
            }
            return false;
        }

        bool isPower(std::string s){
            if (s[0] == '{' && s[s.length()-1] == '}'){
                return true;
            }
            return false;
        }
        
        double convertNum(std::string s){
            try {
                double num = std::stod(s);
                return num;
            } catch (const std::invalid_argument& e) {
                std::cerr << "Invalid argument: " << e.what() << std::endl;
            } catch (const std::out_of_range& e) {
                std::cerr << "Out of range: " << e.what() << std::endl;
            }
            return 0;
        }

        void ProcessTokens(vector<Matrix*> matrices, unordered_map<string, int> MatrixName){
            for (const auto token : Tokens){
                if (isOperator(token)){
                    if (token[0] == '+'){
                        Matrix temp1 = Calculation.top();
                        Calculation.pop();
                        Matrix temp2 = Calculation.top();
                        Calculation.pop();
                        Calculation.push(temp2 + temp1);
                    }else if (token == "-"){
                        Matrix temp1 = Calculation.top();
                        Calculation.pop();
                        Matrix temp2 = Calculation.top();
                        Calculation.pop();
                        Calculation.push(temp2 - temp1);
                    }else if (token == "*"){
                        Matrix temp1 = Calculation.top();
                        Calculation.pop();
                        Matrix temp2 = Calculation.top();
                        Calculation.pop();
                        Calculation.push(temp2 * temp1);
                    }else if (token == "/"){
                        Matrix temp1 = Calculation.top();
                        Calculation.pop();
                        Matrix temp2 = Calculation.top();
                        Calculation.pop();
                        Calculation.push(temp2 / temp1);
                    }else if (token == "^"){
                        ;
                    }
                    
                }else{
                    if (isNumber(token)){
                        double tempNumber = convertNum(token);
                        Matrix *tempMatrix = new Matrix(token, 1, 1, {{tempNumber}});
                        Calculation.push(*tempMatrix);
                        delete tempMatrix;
                    }else if (isVariable(token)){
                        auto it = MatrixName.find(token);
                        if (it != MatrixName.end()) {
                            Calculation.push(*matrices[it->second]);
                        }
                    }else if (isPower(token)){
                        std::string temp = token.substr(1, token.length()-2);
                        if (temp == "-1"){
                            Matrix temp1 = Calculation.top();
                            Calculation.pop();
                            Calculation.push(temp1.inverse());
                        }else if (temp == "T"){
                            Matrix temp1 = Calculation.top();
                            Calculation.pop();
                            Calculation.push(temp1.transpose());                            
                        }else if (isNumber(temp)){
                            double tempNumber = convertNum(temp);
                            Matrix temp1 = Calculation.top();
                            Calculation.pop();
                            Calculation.push(temp1.operator^(tempNumber)); 
                        }
                    }
                }
            }
        }

        //test
        void printCalculation(string filename){
            std::ofstream file(filename, std::ios::app);
            //std::cout << "print" << Calculation.size() <<std::endl;
            while (!Calculation.empty()){
                Calculation.top().rename(statement);
                Calculation.top().getMatrix(filename);
                Calculation.pop();
            }
        }
        //endtest

};

#endif /* Parser_h */
