#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
    char secret[30], letter[1], guessed[6];
    int sizes, i, guesses, hits;
    bool hit = false;
    guesses = 6;
    sizes = 0;
    i=0;
    hits = 0;

    cout << "The word to be guessed, up to 30 letters ";
    cin >> secret;
    system("cls");

    while(secret[i] != '\0'){
        i++;
        sizes++;
    }

    char word[sizes];
    for (i=0; i<sizes;i++){
        word[i] = '-';
    }
    for(i=0;i<guesses;i++){
        guessed[i] = '-';
    }


    while(guesses > 0 && hits < sizes){
        cout << "remaining guesses "<<guesses<<"\n\n";
        cout << "guessed letters ";
        for(i=0;i<6;i++){
            cout << guessed[i] << " ";
        }
        cout << "\n\nword to be guessed ";
        for (i=0; i<sizes;i++){
            cout << word[i];

        }
        cout << "\n\nType one letter ";
        cin >> letter[0];
        for(i=0; i<sizes;i++){
            if(word[i]=='-'){
                if(secret[i]==letter[0]){
                    hit = true;
                    word[i] = secret[i];
                    hits++;
                }
            }
        }
        if(!hit){
            guesses--;
            for(i=0;i<6;i++){
                if(guessed[i]=='-'){
                    guessed[i] = letter[0];
                    break;
                }
            }
        }
        hit = false;
        system("cls");
    }
    if(hits == sizes){
        cout <<"GAME OVER YOU WIN!!!\n\n";
    }else{
        cout << "GAME OVER YOU LOSE!!!\n\n";
    }

    cout << "The word was ";
    for(i=0; i<sizes; i++){
        cout << secret[i];
    }
    cout << "\n\n";

	return 0;
}
