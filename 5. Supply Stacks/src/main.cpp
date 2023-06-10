#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdio>
#include "llist/llist.h"
#include "stack/stack.h"
using namespace std;

const int MAX_STACKS = 50;

struct Stacks{
    Stack data[MAX_STACKS];
    int size;

    void reverse(){
        for(int i = 0; i < size; i++){
            data[i].reverse();
        }
    }

    void print(){
        for(int i = 0; i < size; i++){
            data[i].print();
        }
    }

    void print_peeks(){
        for(int i = 0; i < size; i++){
            cout << char(data[i].peek());
        }
    }
};

int getSize(const string &file_name){

    ifstream file(file_name);
    string line;

    getline(file, line);
    file.close();
       
    return (line.size() + 1) / 4;
}

void getData(const string &file_name, Stacks &stacks){

    ifstream file(file_name);
    string line;

    while(getline(file, line) && line[1] != '1'){
        
        for(int i = 0; i < line.size(); i++){
            if(line[i] == '['){
                stacks.data[i/4].push(line[++i]); i++;
            }
        }
    }
    file.close();
}

Stacks getInput(const string &file_name){

    Stacks stacks;

    stacks.size = getSize(file_name);
    getData(file_name, stacks);

    stacks.reverse();

    return stacks;
}

void solve(const string &file_name, Stacks &stacks){

    ifstream file(file_name);
    string line;

    while(getline(file, line) && line.size() > 0) {}

    int tot, start, end;

    while(getline(file, line)){
        sscanf(line.c_str(), "move %d from %d to %d", &tot, &start, &end);

        Stack temp;

        for(int i = 0; i < tot; i++) temp.push( stacks.data[start-1].pop() ); 
        for(int i = 0; i < tot; i++) stacks.data[end-1].push( temp.pop() );
    }
    file.close();
}

int main(){
    string file = "input.txt";

    Stacks stacks = getInput(file);

    solve(file, stacks);

    stacks.print_peeks();
}


jghhttcmttdwwfjjjpqjqllwvwffswwqmwmddvndvdrrcwrccfncfcgcjjpjrjzjggczgglhllbzlztlzzswwbqqrvrvqrqcrclrccrbrpbbzhbbzvbbwrwswqwqqgmmgqmqmdqdhdmmfnndpdvvdvdbbmgmqgqgqmqrrsbsrrzcrzrcrvrddpqdpdwwsvshvshvshszhshddjllbjljjwhjwhwppbssdccvzzmvvwrrrhmmbdbggqhgqglglgrrdbdjddjvddzpznzmnnpgnppnznzvzbzvvdtdwdttnzzdpzzqjzjzllhglghgttcbtcbtbjbssqcqtcqtqvttvpvqvggbsszjsjqjllfgfqqhllvsvmmjhhbdbzzrwzzggdfgdgcddgmmjnjhhhgvgwghgfffclffdmmmlclzclzzqgqjqzqwzqzbbbljlplnlrlqlqlhlvlmvvlwltwtqwwznndpdttjjrllpptnngjnnzppjhpjhpjpjmjpmjpptzppjpsprpbpmmshmsmqqnhnjhnjnccdnnqhhgfgmgnmnvvtwvttcbtbnbcnnhjjnpphjpjppshsppmrmrbrlrzlzjlzzvssvfffsjfsjshshppchppprpcclhlmmgwwsddgbdggcqqhsqqbdbzzdffmpmvmpptppjrprrgvvgrrztrtllnblbffpgprpqqwcwjwcjcbbjgbbsgsbgbgwbwrrbcrcjcnnvlnlmnnwcncbcrrgcrggtqqgbbqsqhsqslswsdswscwssbqbppczzpmmnjnfjfpjpqpddpbbgrrnqrnqqnwqnntsnsdnddvhhgrgmmgzmgmwgmwwmfwwnqnjjgqghqhhpzpmpbmpbbqvvjjlvvddcnnglnnhpnhhjghgrgjrjqqgtqggmzzbdbssbpssrjsrsbbpzzsgzzpcpwwfgwfgfccslsmlltlnttpvvcbvbqqqqvlvplvvmnntstffvhvvwfftltjjtftbftfqqnbbmnmqqwbbldbldbddtldtldldbllsggdqgdgfgtggglmmgfgcfgccgttgdgdvgglhhvbbnzbzvbzzvtvntvntvvwgvgcgrrmbmnmttzlzgllpmlpmmscsncnnnfrrvqvmvsvsrvvbvpbbvsvssdnnmvnnnggpmpbbqsqwssjwwtnwwhbwwmcwwjfwfhfvvsnsqqwmmrfmrmcrchhpqprpzpmpzzqqmqbqjjbffjnnhphdpdjjbcjcsjcjcdcrddscsgsqgsqggcscrssscvcncfccptcccjgjqqlppjbpjpgpzpgpqqzwqwcwnwccmnnnwrnrttjqtjtllbslsrlrggjrrjwrwmrrcbbnddzcdzcchqqrhhcrcrlrmrcchcpcmcrrlqltlhttdhhjrrzllwjjfvvzccmwwtlwwhpwwssfdsfdsfsddwbbfsfqfwqffhqfqvqwwhfhrrwhrwhrwrzrwrzwwbsblslzzrwzwdwnwznnbsnsbbgffjppvqppbmmdffgghrrchrhfhthqthqhvvrcvrrfvfbvffmmbjmjbbwhhvqvbvjjfzjzvvwnvncvvdssfffjfhjhbbdhdlllmrlmrllbtltbbhnnczzwjzwjwllvtvmvpvvmmfnmnwmwjwrrqtqlltwllwrllsvvdrvrnvrnnsjnjfnnmpnpgnglnggbnbmmcmddhrdrjdjtthssdbssjtjvttqwqppwbpblljnlnljlfjffvddtzzqfzqqjttqhhhvppghpghpghghjggsrrczzqvvbjbbbglldcdrdqdpqpwpffnjnhnthhtlhhrdrcrwrvrlvrlvrvprpccmffqzffdbdhhwjjgmgzzqhqnqsstltjjzszpsppdpnddrnrmrllhtwnlhgzgvsfjfmgfcnnzqhbfztnzhnctmjjhvzrhjcptzqqtstlmrgnbcpnctjgswhfcmtzgsndfzdlqsrlcjrssmjndgrzgvtgfjwtcqwnzmrgtgngcwcwzvttqcdwqspzldfmzgmfclwgqvvvqhhhswpdjlbpjpppdljbdjrbblbrtftdsmvmfpftdlvhdphzbcwwwjvmsjczbtblwbtszmbcmpbdqnwcgcltbdzbsvtjhlqgrsgqzztqrvmswtzgvsjslgvjcvhqftdcmwqwhgwrmrpfdqvfqhczlztrhjqlppchgspfjwzvfsncdhgnlnnshwsbvqmqwtldtmshhqpqbdzqlwfvvbbzwqvlvqdwcpbtrsrhmrjnzmqjttthhbbdjwtzhwjcvhzrtgfwltqhmzwtqbgjjpphlfwfhgctmwpqrmngfrfmbmcqpqcrsmzhjzdzbppbfwpgdtdjvjdvbwfcbddjpjbgtrjtddlpvnppcwhbbgpqgmcrwmfsvqspdvctvljbhcgnllzdpjmjdqwflrfqrsfqnhcsbtszjfmqvjwmcsghwcssbnzzpsggbmpdqrlctrcrmbzlnnqcfmrpfwsnjcggtqncwddsjjzwvlnfpwjlrgwrrvfhgtjwqlblnsnrddjqqtwtzrvfqfqcjhbwtlmfsfgpzgtdddtlvqlqgjwpprpzvdhvlfjbqqflbnvgsgblfpcqprlqrhrrddjjftbmfgghrrrhmttmnfzgmrzwcscnsmdnnddsbdjswhwmjfjnfvjbtcqjlflzjsqqhldcdsbjttmvmcdbwrfwdlllbbjhbmdhnfgwmmbpbsrmqptppqzwtncnwwsjjrchgpvdcsspfqpczmsqfrgvfgsnhfmplrnhzddlbvnthltpwbbzdwwnmhmllwfphhfpnghgdzlzgpbvsphbhvfmcvqpqvdsjjbnbsdvccbmgwdbgsnhpgfshzzznjdbngsrqpwhqjqdfsnmngzznwgvqrtjmzcmbbqjgjcdjdqbmdrgvqflsstqhgsgpfnmzvrdgztlzlhvdjdcslwbgldwjwftvczvtbpdtdqtqshqrbpvpgbfbtnnlmzrhdtsjdlllbtwqgcfphssqmszmbllnbpwvhfdllwtcbqccmbtscmsvppjjrcpswgtzgvhblvbmcddhhgqghbtwzffscsvzgwjdfldccbcfptpmmfbwqzlqhdrcdvhpnwvddqcrwwlmtgvrcvlbvtblhhmhdrvvnpmrdqsgjdrfprfcmtfsbrmsglfjcnjwvpjqlptrbmrqcrdfccmfvhqzrmwqbbmtmjrbnmvzdbwcfpwjzrjrhzrncpwptswhnrgsdpdfjqcjhnvvftgzdccpsgdqcqzfvbtftrzljqmjbgmmlrdlvpwqddmdhzsslzlnvfrblfzfpwtvhpwhmqmbzvchndbzfswtmvcprhlssmncfdqcpzjczptptgdzpjvrqtrlcgbhlqqwvnsrrvtllldbhztgnlmjbmqmgcpcbwtthnhwghnqgvqtnnltbzslmmbjbhqtrmqbgccphjsgwbtstvjnpjjqsdwdsgcrjgznntsgvlrgzmbnzdmbghrmtscppgmztfbsqczzvhsmjmmclhrcbgnvjbgffgbrhrdwccplpdfzcljgfntjlzmsqrwrmdqbclffbfpscddcfsbpsnnphjvjwsfvbprsgpcnbrblvvqfvngbhgmmglzzfmmpnnrphwrvqnmffwpsmmrlhmnsdvbdgjlrjmsdzjltgmjfplrrfmgbhzltzzfpwtqcqwbgsgwfbmntzsvtqqtnrhbtbnshfmwwzbvtsqmtsfssrcvgngvvhjlcnfsvltpsdjspgmmrqttcsltjzqglpspmgrnbrtnbtnjzprqmtfhgczjrlqdhsjqjbhpnwhrffmhvqfmlzcpfflptgqwthfzvspbjjdwmmbnttbztzpnjmlstgmgqbptdncqgbdbdnqwslwhfrdfvmbbqlzhdptpfrhnvcchpddngslzzrhsrwclpccbqhcscbzcpdtwmppvrpjnnjfgrswndtzprjnsvvdwwhhbcsglnwwptptdzgsmbwppdrhwpqhzlgfcsqtfzvqdvcsbtbqvtfvwlcdrwttgmwhbjlqphclqfzmlb