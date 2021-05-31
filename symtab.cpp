#include "symtab.h"
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <map>
#include <vector>
#include <regex>


using namespace std;


void SymbolTable::initReserved(){
     ifstream resFile ("reserved.txt");
     string tok_name;
     int tok_type;
     while (resFile >> tok_name >> tok_type)
     {
          switch (tok_type)
          {
               tokenType tt;
               case 287:
                  tt = tokenType::AUTO;
                 this->symMap.insert(pair<string, shared_ptr<Token>>(tok_name, shared_ptr<Token>(new Token (tt, tok_name))));
                 break;   

               case 314:
                  tt = tokenType::BREAK;
                 this->symMap.insert(pair<string, shared_ptr<Token>>(tok_name, shared_ptr<Token>(new Token (tt, tok_name))));
                 break;
               
               case 304:
                  tt = tokenType::CASE;
                 this->symMap.insert(pair<string, shared_ptr<Token>>(tok_name, shared_ptr<Token>(new Token (tt, tok_name))));
                 break;

               case 289:
                  tt = tokenType::CHAR;
                 this->symMap.insert(pair<string, shared_ptr<Token>>(tok_name, shared_ptr<Token>(new Token (tt, tok_name))));
                 break;
               
               case 297:
                  tt = tokenType::CONST;
                 this->symMap.insert(pair<string, shared_ptr<Token>>(tok_name, shared_ptr<Token>(new Token (tt, tok_name))));
                 break;

               case 313:
                  tt = tokenType::CONTINUE;
                 this->symMap.insert(pair<string, shared_ptr<Token>>(tok_name, shared_ptr<Token>(new Token (tt, tok_name))));
                 break;

               case 305:
                  tt = tokenType::DEFAULT;
                 this->symMap.insert(pair<string, shared_ptr<Token>>(tok_name, shared_ptr<Token>(new Token (tt, tok_name))));
                 break;

               case 310:
                  tt = tokenType::DO;
                 this->symMap.insert(pair<string, shared_ptr<Token>>(tok_name, shared_ptr<Token>(new Token (tt, tok_name))));
                 break;   

               case 296:
                  tt = tokenType::DOUBLE;
                 this->symMap.insert(pair<string, shared_ptr<Token>>(tok_name, shared_ptr<Token>(new Token (tt, tok_name))));
                 break;
               
               case 307:
                  tt = tokenType::ELSE;
                 this->symMap.insert(pair<string, shared_ptr<Token>>(tok_name, shared_ptr<Token>(new Token (tt, tok_name))));
                 break;

               case 302:
                  tt = tokenType::ENUM;
                 this->symMap.insert(pair<string, shared_ptr<Token>>(tok_name, shared_ptr<Token>(new Token (tt, tok_name))));
                 break;
               
               case 285:
                  tt = tokenType::EXTERN;
                 this->symMap.insert(pair<string, shared_ptr<Token>>(tok_name, shared_ptr<Token>(new Token (tt, tok_name))));
                 break;

               case 295:
                  tt = tokenType::FLOAT;
                 this->symMap.insert(pair<string, shared_ptr<Token>>(tok_name, shared_ptr<Token>(new Token (tt, tok_name))));
                 break;

               case 311:
                  tt = tokenType::FOR;
                 this->symMap.insert(pair<string, shared_ptr<Token>>(tok_name, shared_ptr<Token>(new Token (tt, tok_name))));
                 break;

               case 312:
                  tt = tokenType::GOTO;
                 this->symMap.insert(pair<string, shared_ptr<Token>>(tok_name, shared_ptr<Token>(new Token (tt, tok_name))));
                 break;   

               case 306:
                  tt = tokenType::IF;
                 this->symMap.insert(pair<string, shared_ptr<Token>>(tok_name, shared_ptr<Token>(new Token (tt, tok_name))));
                 break;
               
               case 291:
                  tt = tokenType::INT;
                 this->symMap.insert(pair<string, shared_ptr<Token>>(tok_name, shared_ptr<Token>(new Token (tt, tok_name))));
                 break;

               case 292:
                  tt = tokenType::LONG;
                 this->symMap.insert(pair<string, shared_ptr<Token>>(tok_name, shared_ptr<Token>(new Token (tt, tok_name))));
                 break;
               
               case 288:
                  tt = tokenType::REGISTER;
                 this->symMap.insert(pair<string, shared_ptr<Token>>(tok_name, shared_ptr<Token>(new Token (tt, tok_name))));
                 break;

               case 315:
                  tt = tokenType::RETURN;
                 this->symMap.insert(pair<string, shared_ptr<Token>>(tok_name, shared_ptr<Token>(new Token (tt, tok_name))));
                 break;

               case 290:
                  tt = tokenType::SHORT;
                 this->symMap.insert(pair<string, shared_ptr<Token>>(tok_name, shared_ptr<Token>(new Token (tt, tok_name))));
                 break;

               case 293:
                  tt = tokenType::SIGNED;
                 this->symMap.insert(pair<string, shared_ptr<Token>>(tok_name, shared_ptr<Token>(new Token (tt, tok_name))));
                 break;   

               case 261:
                  tt = tokenType::SIZEOF;
                 this->symMap.insert(pair<string, shared_ptr<Token>>(tok_name, shared_ptr<Token>(new Token (tt, tok_name))));
                 break;
               
               case 286:
                  tt = tokenType::STATIC;
                 this->symMap.insert(pair<string, shared_ptr<Token>>(tok_name, shared_ptr<Token>(new Token (tt, tok_name))));
                 break;

               case 300:
                  tt = tokenType::STRUCT;
                 this->symMap.insert(pair<string, shared_ptr<Token>>(tok_name, shared_ptr<Token>(new Token (tt, tok_name))));
                 break;
               
               case 308:
                  tt = tokenType::SWITCH;
                 this->symMap.insert(pair<string, shared_ptr<Token>>(tok_name, shared_ptr<Token>(new Token (tt, tok_name))));
                 break;

               case 284:
                  tt = tokenType::TYPEDEF;
                 this->symMap.insert(pair<string, shared_ptr<Token>>(tok_name, shared_ptr<Token>(new Token (tt, tok_name))));
                 break;

               case 301:
                  tt = tokenType::UNION;
                 this->symMap.insert(pair<string, shared_ptr<Token>>(tok_name, shared_ptr<Token>(new Token (tt, tok_name))));
                 break;

               case 294:
                  tt = tokenType::UNSIGNED;
                 this->symMap.insert(pair<string, shared_ptr<Token>>(tok_name, shared_ptr<Token>(new Token (tt, tok_name))));
                 break;

               case 299:
                  tt = tokenType::VOID;
                 this->symMap.insert(pair<string, shared_ptr<Token>>(tok_name, shared_ptr<Token>(new Token (tt, tok_name))));
                 break;
               
               case 298:
                  tt = tokenType::VOLATILE;
                 this->symMap.insert(pair<string, shared_ptr<Token>>(tok_name, shared_ptr<Token>(new Token (tt, tok_name))));
                 break;

               case 309:
                  tt = tokenType::WHILE;
                 this->symMap.insert(pair<string, shared_ptr<Token>>(tok_name, shared_ptr<Token>(new Token (tt, tok_name))));
                 break;
               
          }
     } 
}

shared_ptr<Token> SymbolTable::lookupToken(string text){
     
     auto it = this->symMap.find(text);
     if (it != this->symMap.end()){
     return it->second;
     }
     else{
        return nullptr;
     }
}

void SymbolTable::insertToken(string text, shared_ptr<Token> tokenp){
     this->symMap.insert({text, tokenp});
     
     
}

void SymbolTable::xref(){
     for (auto& tkn : symMap)
	{
		string token_name = tkn.first;
		shared_ptr<Token> token_ptr = tkn.second;
		if (token_ptr->getType() == IDENTIFIER)
		{
			shared_ptr<set<int>> tkn_lines = token_ptr->getLines();
			set<int>::iterator it;
         cout << token_name << "\t";
			for (it = tkn_lines -> begin(); it != tkn_lines -> end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;
		}
	}
}

