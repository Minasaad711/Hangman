#include <iostream>
#include <ctime>
#include <string>

using namespace std;
void lvl(int& x)
{
    cin >> x;
}
void out()
{
    cout << "hangman by" << endl << "Diaa el din Amr     \t" << "Mohamed Mazroa" << endl
        << "Youssef Khaled      \t" << "Mina George" << endl;
    cout << "_______" << endl;
    cout << "|          )         " << endl;
    cout << "|          0         " << endl;
    cout << "|         /|\\       " << endl;
    cout << "|        / | \\      " << endl;
    cout << "|          |         " << endl;
    cout << "|         / \\       " << endl;
    cout << "|        /   \\      " << endl;
    cout << "|                    " << endl;
    cout << "|________" << endl;
    cout << "press any key to continue" << endl;
}
struct bylen
{
    bool correctguess = false;
};
int main()
{
    //Start Screen
    char start{};
    out();
    cin >> start;

    //the Game!!!!

    // set the variables used throughout the game

    int tries, category, level, counter = 1, playagain = 0; // number of tries to guess correctly and the category the user will choose

    char guess;//letter guessed by the player
    bylen x;
    x.correctguess = false;
    char preguesses[7];// an array needs to be 1 more than the user guesses for the null terminator
    preguesses[0] = '\0';
    for (int i = 1; i < 6; i++)
    {
        preguesses[i] = '-';
    }
    preguesses[6] = '\0';

    string word;//this will be the word the user has to guess

    //the switch in which all the categories will be put
    string wordlist[3][33] = { {"arctic_fox", "black_bear", "bloodhound", "blue_whale", "bull_shark", "cuttlefish",
                                "horn_shark", "polar_bear", "sea_turtle", "wildebeest", "woodpecker", "eskimo_dog",
                                "rhinoceros", "rattlesnake", "hippopotamus","centipede","opossum", "cockatoo",
                                "lyrebird", "lovebird", "kodiak_bear", "malabar_rat", "deinoceras", "pouched_rat",
                                "raccoon", "dogprairie_dog", "persian_cat", "spring_hare", "paddymelon",
                                "jack_rabbit", "herring_hog", "hartebeest","angwantibo"},
                               {"elephant", "goldfish", "kangaroo", "scorpion", "sea_horse", "starfish", "squirrel",
                                "butterfly", "crocodile", "dinosaur", "dragonfly", "earthworm", "jellyfish",
                                "sea_snail", "tiger_cat", "white fox", "armadillo", "swordfish", "bald_eagle",
                                "sand_piper", "alligator", "glow_worm", "albatross", "honey_bee", "king_crab",
                                "snowy_owl", "wolverine", "wild_boar", "flamingo", "sea_otter", "mandrill", "tree_frog","ladybird"},
                               {"cheetah", "dolphin", "gazelle", "giraffe", "hamster", "leopard", "tigress",
                                "zebra", "turtle", "camel", "tiger", "eagle", "horse", "llama","mouse", "horse",
                                "lizard", "insect", "spider", "donkey", "monkey", "pigeon","rabbit", "squirl",
                                "falcon", "gibbon","dragon", "buffalo", "octopus", "panther","chicken", "gorilla","panda"} };//this is an array of 33x2 strings
    string wordlist2[3][33] = { {"microsoft","citigroup","mitsubishi","petrochina","alfaromeo","brilliance",
                                 "astonmartin","cadillac","chevrolet","daihatsu","chrysler","lamborghini",
                                 "mercedesbenz","panasonic","volekswagen","mastercard","fresenius","exxomobil"
                                 ,"swisscorn","santander","transneft","starbucks","publicbank","fristenergy",
                                 "bridgestone","unicredit","whirlpool","accelormittal","schlumberger",
                                 "fristrand","albertsons","cognizant","acopetrol"},
                                {"samsung","bentley","prrologis","alphabet","bigatti","labcrop","walmart",
                                 "citroen","reycrop","allianz","ferrari","gazprom","comcast","hyundai",
                                 "fujitsu","softbank","lincoln","nintende","sinopec","peugout","chevron",
                                 "philips","porshe","pepsico","novartis","centene","etisalat","metlife",
                                 "netflix","stryker","sanofi","inditex","renault"},
                                {"apple","amazon","intel","nestle","cigna","phizer","oracle","abbvie","anthem"
                                 ,"buick","chana","chery","daewoo","dodge","honda","hummer","isuzu","jaguar",
                                 "lexus","mazda","nissan","nissan","proton","skoda","subaro","tesla","toyota",
                                 "volvo","xiaomi","kroger","danone","baidu","adobe"} };//this is an array of 100 strings
    string wordlist3[3][33] = { {"alessandro","nightingale","oppenheimer","gaposchkin","rutherford",
                                 "sommerfeld","staudinger","alexandria","winogradsky","chandrasekhar",
                                 "landsteiner","leeuwenhoek","montalcini","mcclintock","christiane",
                                 "anaximander","archimedes","aristarchus","brongniart","macfarlane",
                                 "washington","subrahmanyan","copernicus","dobzhansky","eratosthenes",
                                 "empedocles","heisenberg","christiaan","kammerlingh","philoponus",
                                 "sherrington","yakovlevich","whitfield"},
                                {"agassiz","gaetana","battani","alhazen","alkhalili","muhammad","mihailo"
                                        ,"anderson","virginia","avicenna","avogadro","charles","francis","bardeen"
                                        ,"william","beckman","behring","berliner","bernard","timothy","bessemer",
                                        "jehangir","birdseye","blalock","chandra","wilhelm","lawrence","wernher"
                                        ,"alexander","buckland","benjamin","santiago","coulumb"},
                                {"salim","agnes","apgar","newton","bacon","baird","barba","barkla","beadle",
                                 "arnold","henri","adolf","emile","daniel","bethe","alfred","james","franz",
                                 "david","niels","bosch","robert","georg","boyle","bragg","brahe","brand",
                                 "brandt","bretz","louis","brown","isaac","euler"} };//this is an array of 100 strings
    string wordlist4[3][33] = { {"algorithm","bootstrap","exception","framework","Iteration","statements","compilation"
                                 ,"declaration","conditionals","expressions","arithmetic","stdatomic","assignment",
                                 "augmented","autonomous","conditional","development","tensorflow","Aggregation",
                                 "associative","automation","backpropagation","satisfiability","refactoring","commutative"
                                 ,"complementarity","constructor","compressor","declarative","decompiler",
                                 "decrement","deductive","dependent"},
                                {"program","boolean","objects","runtime","default","include","blockly","command",
                                 "constant","backend","pointer","summary","iostream","argument","variable","operand",
                                 "package","keywords","hardcode","template","csingal","version","cstdint","cassert",
                                 "concepts","climits","cwctype","cstring","iterator","numbers","ostream","fstream","sstream"},
                                {"bytes","build","click","cloud","array","syntax","break","token","coding","return",
                                 "class","using","float","switch","binary","double","ctime","cfloat","source","string"
                                 ,"vector","stack","ratio","locale","regex","atomic","stdio","wchar","queue","ranges",
                                 "tuple","memory","bitset"} };//this is an array of 100 strings
    while (playagain != 1)
    {
        cout << "please choose a cetgory from the following (enter the number):\n" << "1.Animals\t"
            << "2.Brand Names\n" << "3.Scientists\t\t" << "4.Programming\n\n";
        cin >> category;
        cout << "now please choose a level of difficulty: " << "1.hard\t" << "2.medium\t" << "3.easy\n";
        lvl(level);

        while (counter <= 30)
        {
            srand(time(nullptr));
            int Randnum = rand() % 33; //picks a number between 0 and 33 randomly

            switch (category) {
            case 1: { switch (level) {
            case 1: {
                tries = 7;
                word = wordlist[level - 1][Randnum];
                break;
            }
            case 2: {
                tries = 6;

                if (counter <= 10) {
                    word = wordlist[level - 1][Randnum];
                }
                else if (counter > 10 && counter <= 20) {
                    word = wordlist[level][Randnum];
                }
                break;
            }
            case 3: {
                if (counter <= 10) {
                    word = wordlist[level - 1][Randnum];
                }
                else if (counter > 10 && counter <= 20) {
                    word = wordlist[level][Randnum];
                }
                else {
                    word = wordlist[level + 1][Randnum];
                }
                tries = 5;
                break;
            }
            default: {cout << endl; }
            }
                  break;
            }
            case 2: {
                switch (level) {
                case 1: {
                    tries = 7;
                    word = wordlist2[level - 1][Randnum];
                    break;
                }
                case 2: {
                    tries = 6;

                    if (counter <= 10) {
                        word = wordlist2[level - 1][Randnum];
                    }
                    else if (counter > 10 && counter <= 20) {
                        word = wordlist2[level][Randnum];
                    }
                    break;
                }
                case 3: {
                    if (counter <= 10) {
                        word = wordlist2[level - 1][Randnum];
                    }
                    else if (counter > 10 && counter <= 20) {
                        word = wordlist2[level][Randnum];
                    }
                    else {
                        word = wordlist2[level + 1][Randnum];
                    }
                    tries = 5;
                    break;
                }
                default: {cout << endl; }
                }
                break;
            }
            case 3: {
                switch (level) {
                case 1: {
                    tries = 7;
                    word = wordlist3[level - 1][Randnum];
                    break;
                }
                case 2: {
                    tries = 6;

                    if (counter <= 10) {
                        word = wordlist3[level - 1][Randnum];
                    }
                    else if (counter > 10 && counter <= 20) {
                        word = wordlist3[level][Randnum];
                    }
                    break;
                }
                case 3: {
                    if (counter <= 10) {
                        word = wordlist3[level - 1][Randnum];
                    }
                    else if (counter > 10 && counter <= 20) {
                        word = wordlist3[level][Randnum];
                    }
                    else {
                        word = wordlist3[level + 1][Randnum];
                    }
                    tries = 5;
                    break;
                }
                default: {cout << endl; }
                }
                break;
            }
            case 4: {
                switch (level) {
                case 1: {
                    tries = 7;
                    word = wordlist4[level - 1][Randnum];
                    break;
                }
                case 2: {
                    tries = 6;

                    if (counter <= 10) {
                        word = wordlist4[level - 1][Randnum];
                    }
                    else if (counter > 10 && counter <= 20) {
                        word = wordlist4[level][Randnum];
                    }
                    break;
                }
                case 3: {
                    if (counter <= 10) {
                        word = wordlist4[level - 1][Randnum];
                    }
                    else if (counter > 10 && counter <= 20) {
                        word = wordlist4[level][Randnum];
                    }
                    else {
                        word = wordlist4[level + 1][Randnum];
                    }
                    tries = 5;
                    break;
                }
                default: {cout << endl; }
                }
                break;
            }
            default: {cout << endl; }
            }


            cout << word;
            string Mysteryword(word.length(), '*');//replaces each letter of the word with astric and stores it in  mystry word
            //cout<<Mysteryword<<endl;//test the word(although we'll use this later on)

            while (tries >= 0) {
                //reset the bool value

                x.correctguess = false;

                //giving information about the word for the player

                cout << "\nthe word u have to guess is:\n\n";
                cout << Mysteryword << endl << endl;
                cout << "there are " << Mysteryword.length() << " letters in the word\n";
                cout << "you have " << tries << " tries left\n";
                if (preguesses[0] == '\0') {
                    cout << endl;
                }
                else {
                    cout << "You have guessed:" << preguesses << endl;
                }
                cout << "guess a letter:\t";
                cin >> guess;

                //check if guess is correct

                for (int i = 0; i < Mysteryword.length(); i++)//for the length of the word(using mystery)
                {
                    if (word[i] == guess) //checking if word has the guess in it
                    {
                        Mysteryword[i] = guess;
                        x.correctguess = true;
                        if (word == Mysteryword) {
                            cout << "\n\nCongratulations your guess is correct: " << Mysteryword << endl;
                            if (counter >= 30) {
                                cout << "if you want to play again press 1:";
                                cin >> playagain;
                            }
                            counter++;
                            tries = -1;
                            break;
                        }
                    }

                }
                if (!x.correctguess) {
                    tries--;
                    cout << "sorry but, " << guess << " is not a part of the word\n";
                }
                else {
                    cout << "correct guess!!\n";
                }
                switch (tries) {
                case 6: {
                    cout << "_______" << endl;
                    cout << "|          )         " << endl;
                    cout << "|                    " << endl;
                    cout << "|                    " << endl;
                    cout << "|                    " << endl;
                    cout << "|                    " << endl;
                    cout << "|                    " << endl;
                    cout << "|                    " << endl;
                    cout << "|                    " << endl;
                    cout << "|________" << endl;
                    break;
                }
                case 5: {
                    cout << "_______" << endl;
                    cout << "|          )         " << endl;
                    cout << "|          0         " << endl;
                    cout << "|                    " << endl;
                    cout << "|                    " << endl;
                    cout << "|                    " << endl;
                    cout << "|                    " << endl;
                    cout << "|                    " << endl;
                    cout << "|                    " << endl;
                    cout << "|________" << endl;
                    if (!x.correctguess) {
                        preguesses[0] = guess;
                    }
                    break;
                }
                case 4: {
                    cout << "_______" << endl;
                    cout << "|          )         " << endl;
                    cout << "|          0         " << endl;
                    cout << "|          |         " << endl;
                    cout << "|          |         " << endl;
                    cout << "|          |         " << endl;
                    cout << "|                    " << endl;
                    cout << "|                    " << endl;
                    cout << "|                    " << endl;
                    cout << "|________" << endl;
                    if (!x.correctguess) {
                        preguesses[1] = guess;
                    }
                    break;
                }
                case 3: {
                    cout << "_______" << endl;
                    cout << "|          )         " << endl;
                    cout << "|          0         " << endl;
                    cout << "|          |\\       " << endl;
                    cout << "|          | \\      " << endl;
                    cout << "|          |         " << endl;
                    cout << "|                    " << endl;
                    cout << "|                    " << endl;
                    cout << "|                    " << endl;
                    cout << "|________" << endl;
                    if (!x.correctguess) {
                        preguesses[2] = guess;
                    }
                    break;
                }
                case 2: {
                    cout << "_______" << endl;
                    cout << "|          )         " << endl;
                    cout << "|          0         " << endl;
                    cout << "|         /|\\       " << endl;
                    cout << "|        / | \\      " << endl;
                    cout << "|          |         " << endl;
                    cout << "|                    " << endl;
                    cout << "|                    " << endl;
                    cout << "|                    " << endl;
                    cout << "|________" << endl;
                    if (!x.correctguess) {
                        preguesses[3] = guess;
                    }
                    break;
                }
                case 1: {
                    cout << "_______" << endl;
                    cout << "|          )         " << endl;
                    cout << "|          0         " << endl;
                    cout << "|         /|\\       " << endl;
                    cout << "|        / | \\      " << endl;
                    cout << "|          |         " << endl;
                    cout << "|         /          " << endl;
                    cout << "|        /           " << endl;
                    cout << "|                    " << endl;
                    cout << "|________" << endl;
                    if (!x.correctguess) {
                        preguesses[4] = guess;
                    }
                    break;
                }
                case 0: {
                    cout << "_______" << endl;
                    cout << "|          )         " << endl;
                    cout << "|          0         " << endl;
                    cout << "|         /|\\       " << endl;
                    cout << "|        / | \\      " << endl;
                    cout << "|          |         " << endl;
                    cout << "|         / \\       " << endl;
                    cout << "|        /   \\      " << endl;
                    cout << "|                    " << endl;
                    cout << "|________" << endl;
                    tries = -1;
                    cout << "\nGAME OVER!!!!!\n" << "the word was: " << word;
                    break;
                }
                default:
                    cout << "if u are seeing this line then there is an error";
                }
            }
        }
    }
    return 0;