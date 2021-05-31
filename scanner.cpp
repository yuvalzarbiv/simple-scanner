#include "scanner.h"
#include <string>
#include <string_view>
#include <regex>
#include <assert.h>

#define D [0-9]
#define L	[a-zA-Z_]
#define E	[Ee][+-]?{D}+
#define WS [ \t\n]

using namespace std;

shared_ptr<Token> Scanner::nextToken(){
     //bool flag_next_char = nextChar();
     char tmp_ch;
while(nextChar() ){
          
         if(ch == ' '){
               nextChar();
         }
         if (ch == '/'){
              
            int i = lineno;
            nextChar();
            if(ch == '/'){
                while (i == lineno)
                {
                    nextChar();
                } 
            }
            else if(ch == '*'){
                while(ch != '/'){
                    nextChar();
                }
                nextChar();

            }
        }
     
     

//handle double special signs

    
     
     if(isdigit(ch) || ch == '.' || ch == '-'){

          string curr_num = string(1, ch);
          while (nextChar())
          {
               if(isdigit(ch) || ch == 'E' || ch == 'e' ||ch == '.' || ch == '+'){
                    curr_num += ch;
                    
               }
               else if(curr_num == "."){
                    inputFile.unget();
                    return shared_ptr<Token>(new Token(static_cast<tokenType>('.'),"."));
               }
               else if(curr_num == "-"){
                    if(ch == '>') {
                         return shared_ptr<Token>(new Token(PTR_OP,"->"));
                    }
               }
               else {
                    inputFile.unget();
                    regex number ("[0-9]");
                    regex number1 (R"([1-9](\d)*)");
                    regex number2(R"((\d)+[Ee][+-]?(\d)+)");
                    regex number3(R"((\d)*\.(\d)+([Ee][+-]?(\d)+)?)");
                    regex number4(R"((\d)+\.(\d)*([Ee][+-]?(\d)+)?)");
                    if(regex_match(curr_num, number) ||regex_match(curr_num, number1) || regex_match(curr_num,number2) || regex_match(curr_num, number3) || regex_match(curr_num, number4)){
                         return shared_ptr<Token>(new Token(CONSTANT,curr_num));           

                    }else{
                         return shared_ptr<Token>(new Token (ERROR, curr_num));
                     }     
                }
          }  
     }

     if(ch == '"'){
          string str_lit = string(1, ch);
          while(nextChar()){
               str_lit += ch;
               if (ch == '"') break;
          }
          regex str_literal_rgx("\"[^\"]*\"");
          if(regex_match(str_lit, str_literal_rgx)){
               return shared_ptr<Token>(new Token(STRING_LITERAL, str_lit.substr(1, str_lit.length()-2)));
          }else{
               return shared_ptr<Token>(new Token (ERROR, str_lit.substr(1, str_lit.length()-2)));
          }
     }


     if(ch == '\''){
          string str_const = string(1, ch);
          while(nextChar()){
               str_const += ch;
               if (ch == '\'') break;
          }
          regex cons_rgx("\'[^\']\'");
          if(regex_match(str_const, cons_rgx)){
               return shared_ptr<Token>(new Token(CONSTANT, str_const.substr(1, str_const.length()-2)));
          }else{
               return shared_ptr<Token>(new Token (ERROR,str_const.substr(1, str_const.length()-2)));
          }
     }

     if(isalpha(ch)){
          string curr_word = "";
          curr_word = ch;
          string tmp_word;
          
               while (nextChar() && regex_match(string(1, ch), regex(R"(\w(\w|\d)*)")))
               {  
                    tmp_word += ch;
               }

               inputFile.unget();
               tmp_word = curr_word + tmp_word;
               auto in_table = symTab.lookupToken(tmp_word);

               if(in_table == nullptr){
                    auto id_ptr = shared_ptr<Token>(new varToken (tmp_word));
                    id_ptr->add_line(lineno);
                    symTab.insertToken(tmp_word, id_ptr);
               

                    return id_ptr;
               } else if(in_table->getType() == IDENTIFIER){
                    in_table->add_line(lineno);
                    return in_table;
               }  
     
     return in_table;

          }


 //handle single special signs

     else{
          
          switch (ch) { // each character represents itself

          case '+' : 
                         if (inputFile.peek() == '+'){
                              nextChar();
                               return shared_ptr<Token>(new Token(INC_OP,"=="));
                         }
                         else{
                              return shared_ptr<Token>(new Token(static_cast<tokenType>('+'),"+"));
                         }
                        
          case '-' :
                         if(inputFile.peek() == '-') {
                               nextChar();
                              return shared_ptr<Token>(new Token(DEC_OP,"--"));
                         }
                         else if(inputFile.peek() == '>') {
                               nextChar();
                               return shared_ptr<Token>(new Token(PTR_OP,"->"));
                         }
                         else{
                              return shared_ptr<Token>(new Token(static_cast<tokenType>('-'),"-"));
                         }
                        
          
          case '&' : 
                         if(inputFile.peek() == '&'){
                              nextChar();
                           return shared_ptr<Token>(new Token(AND_OP,"&&"));
                         }
                         else{
                              return shared_ptr<Token>(new Token(static_cast<tokenType>('&'),"&"));
                         }
                         
                          

          case '|' : 
                         if(inputFile.peek() == '|') {
                              nextChar();
                              return shared_ptr<Token>(new Token(OR_OP,"||"));
                         }
                         else{
                              return shared_ptr<Token>(new Token(static_cast<tokenType>('|'),"|"));
                         }

          case '<' :
                         if(inputFile.peek() == '=') {
                               nextChar();
                              return shared_ptr<Token>(new Token(LE_OP,"<="));
                         }
                         else{
                              return shared_ptr<Token>(new Token(static_cast<tokenType>('<'),"<"));
                         }

          case '>' : 
                         if(inputFile.peek() == '=') {
                              nextChar();
                              return shared_ptr<Token>(new Token(GE_OP,">="));
                         }
                         else{
                              return shared_ptr<Token>(new Token(static_cast<tokenType>('>'),">"));
                         }


           case '=' : 
                         if(inputFile.peek() == '=') {
                              nextChar();
                              return shared_ptr<Token>(new Token(EQ_OP,"=="));
                          }
                         else{
                              return shared_ptr<Token>(new Token(static_cast<tokenType>('='),"="));

                         }

           case '!' :
                         if(inputFile.peek() == '=') {
                               nextChar();
                              return shared_ptr<Token>(new Token(NE_OP,"!="));
                         }
                         else{
                              return shared_ptr<Token>(new Token(static_cast<tokenType>('!'),"!"));
                         }
                      
          case ';' : case '{' : case '}' : case ',' : case ':' : \
          case '(': case ')' : case '[' : case ']' : case '~' : \
          case '*' : case '%' : case '^' : case '?' : case '/': case '.' :
               return shared_ptr<Token>(new Token(static_cast<tokenType>(ch),string(1,ch)));
               break;

               }
          }
     }
}
          


