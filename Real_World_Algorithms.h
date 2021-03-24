#pragma once
#define PART2
#define PART1
//generates random int
#include <random>
#include <functional>
int RAND(int left, int right)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(left, right);

    return dist(gen);
}

#ifdef PART1

#include <array>

//Algorithm 1.1
template <typename T, size_t SIZE>
std::array<T, SIZE>* SimpleStockSpan(std::array<T, SIZE>* quotes)
{
    std::array<T, SIZE>* spans = new std::array<T, SIZE>;

    spans->operator[](0) = 1;
    // std::cout << "i" << "  " << "k" << std::endl;
    for (size_t i = 0; i < SIZE; i++)
    {
        //std::cout << i << std::endl;
        size_t k = 1;
        bool span_end = false;

        while ((int)(i - k) >= 0 && !span_end)
        {
            //std::cout <<"   " << k << std::endl;
            if (quotes->operator[](i - k) <= quotes->operator[](i)) k = k + 1;
            else span_end = true;
        }

        spans->operator[](i) = k;
    }

    return spans;
}
//Algorithm 1.2
#include <vector>
template <typename T, size_t SIZE>
std::array<T, SIZE>* StackStockSpan(std::array<T, SIZE>* quotes)
{
    std::array<T, SIZE>* spans = new std::array<T, SIZE>;
    spans->operator[](0) = 1;
    std::vector<T> S;
    S.push_back(0);

    // std::cout << "i" << "  " << "k" << std::endl;
    for (size_t i = 0; i < SIZE; i++)
    {
        while (!S.empty() && (quotes->operator[](S.back()) <= quotes->operator[](i)))
        {
            S.pop_back();
        }
        if (S.empty())spans->operator[](i) = i + 1;
        else spans->operator[](i) = i - S.back();
        S.push_back(i);
    }

    return spans;
}

#include <random>
#include <type_traits>

//generates random array
template<typename T, size_t SIZE>
std::array<T, SIZE>* GenerateRandomArray()
{
    std::array<T, SIZE>* array = new std::array<T, SIZE>;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 100);

    for (size_t i = 0; i < SIZE; i++)
    {
        array->operator[](i) = (T)dist(gen);
    }

    return array;
}
//print pointer to array
template <typename T, size_t SIZE>
void print(std::array<T, SIZE>* arr)
{
    for (auto& a : *arr)std::cout << a << " "; std::cout << std::endl;
}

//exercise 1.3.1. Stack

template<class T, size_t SIZE = 100>
class ouMyStack
{
    bool is_empty_bool = true;
    size_t current_pos = 0;
    std::array<T, SIZE>* stack;
public:
    ouMyStack() { stack = new std::array<T, SIZE>; }
    bool is_full() { return current_pos == SIZE - 1 ? true : false; }
    bool is_empty() { return is_empty_bool; }
    void push(T x)
    {
        if (!this->is_full()) {
            stack->operator[](current_pos++) = x;
            is_empty_bool = false;
        }
        else
            std::cout << "Stack is full! Push failed." << std::endl;
    }
    void pop()
    {
        if (!is_empty_bool) {
            if (current_pos == 1) { is_empty_bool = true; current_pos--; }
            else current_pos--;
        }
        else std::cout << "Stack is empty! Pop failed." << std::endl;
    }


    T top()
    {
        if (!is_empty_bool)return stack->operator[](current_pos - 1);

        else {
            std::cout << "Stack is empty! top failed.";
            return T();
        }
    }
    size_t size() {
        return current_pos;
    }

    void print()
    {
        if (is_empty_bool)std::cout << "[empty]" << std::endl;
        else {
            std::cout << "[ ";
            for (size_t i = 0; i < current_pos; i++)std::cout << stack->operator[](i) << " "; std::cout << "]";
        }
    }

    void reverse()
    {
        auto* newStack = new std::array<T, SIZE>;
        for (size_t i = 0; i < current_pos; i++)newStack->operator[](i) = stack->operator[](current_pos - 1 - i);
        delete stack;
        stack = newStack;
    }
};

class Calc
{
    ouMyStack<std::string, 10> input;
    ouMyStack<int, 100> output;
public:
    void getExpression(std::string&& str) {
        std::string current = "";
        for (size_t i = 0; i < str.size(); i++)
        {
            if ((str[i] == ' ') || (i == (str.size() - 1))) {
                if (i == (str.size() - 1))
                {
                    current += str[i];
                    input.push(current);
                    break;
                }
                else
                {
                    input.push(current);
                    current = "";
                }
            }
            else current += str[i];
        }

        //input.print(); std::cout << std::endl;
        input.reverse();
        input.print(); std::cout << std::endl;
    }


    void execute() {


        while (!input.is_empty())
        {

            if (isdigit(input.top()[0]))
            {
                output.push(stoi(input.top()));
                input.pop();
            }
            else if (input.top()[0] == '+')
            {
                input.pop();
                int first = output.top(); output.pop();
                int second = output.top(); output.pop();
                output.push(first + second);
            }
            else if (input.top()[0] == '-')
            {
                input.pop();
                int first = output.top(); output.pop();
                int second = output.top(); output.pop();
                output.push(second - first);
            }
            else if (input.top()[0] == '*')
            {
                input.pop();
                int first = output.top(); output.pop();
                int second = output.top(); output.pop();
                output.push(first * second);
            }
            else if (input.top()[0] == '/')
            {
                input.pop();
                int first = output.top(); output.pop();
                int second = output.top(); output.pop();
                output.push(second / first);
            }
            output.print(); if (!input.is_empty())std::cout << ",";

        }
        std::cout << std::endl;
    };
};

class bracers
{
    ouMyStack<char, 100> bracers_stack;
    ouMyStack<char, 10> round_bracers_stack;
    ouMyStack<char, 10> courvie_bracers_stack;
    ouMyStack<char, 10> square_bracers_stack;

public:
    void getExpression(std::string&& br)
    {
        for (size_t i = 0; i < br.size(); i++)
        {
            bracers_stack.push(br[i]);

        }

        bracers_stack.print();
    }

    std::string checkBracers()
    {
        while (!bracers_stack.is_empty())
        {

            if (bracers_stack.top() == '(')
            {
                bracers_stack.pop();

                if (round_bracers_stack.is_empty())return " ) - bracer required";
                else round_bracers_stack.pop();

            }
            else if (bracers_stack.top() == ')')
            {
                bracers_stack.pop();
                round_bracers_stack.push(')');
            }
            else if (bracers_stack.top() == '[')
            {
                bracers_stack.pop();
                if (square_bracers_stack.is_empty())return " ] - bracer required";
                else square_bracers_stack.pop();
            }
            else if (bracers_stack.top() == ']')
            {
                bracers_stack.pop();
                square_bracers_stack.push(']');
            }
            else if (bracers_stack.top() == '{')
            {
                bracers_stack.pop();
                if (courvie_bracers_stack.is_empty())return " } - bracer required";
                else courvie_bracers_stack.pop();
            }
            else if (bracers_stack.top() == '}')
            {
                bracers_stack.pop();
                courvie_bracers_stack.push('}');
            }
            else if (bracers_stack.top() == ' ')bracers_stack.pop();
        }


        if (bracers_stack.is_empty())
        {
            if (!round_bracers_stack.is_empty())return " ( - bracer required";
            if (!square_bracers_stack.is_empty())return " [ - bracer required";
            if (!courvie_bracers_stack.is_empty())return " { - bracer required";

        }
        return " everithing fine";
    }

};

#endif

#ifdef PART2
//2.1
template <class T>
class ouMyList
{
    struct Node {
        T data;
        Node* next;
    };

    Node* first = nullptr;

public:
    ouMyList() {};
    Node* insert(T&& after, T&& data) {

        Node* n = new Node();
        n->data = data;

        if (first == nullptr)
        {
            first = n;
            n->next = nullptr;
        }
        else
        {
            Node* current = find(std::move(after));
            n->next = current->next;
            current->next = n;
        }

        return n;
    };
    Node* insert(T&& data) {

        Node* n = new Node();
        n->data = data;
        n->next = first;
        first = n;

        return n;
    };

    Node* find(T&& data)
    {
        Node* current = first;
        while (current != nullptr)
        {
            if (current->data == data) return current;
            else current = current->next;
        };
        return nullptr;
    };

    Node* find_prev(T&& data)
    {
        if (first != nullptr && first->data == data) return nullptr;

        Node* current = first;
        while (current != nullptr)
        {
            if (current->next->data == data)  return current;
            else current = current->next;
        };
        return nullptr;
    };

    void remove(T&& data) {

        auto current = find(std::move(data));
        if (current == first)
            if (first->next == nullptr) { delete first; first = nullptr; }
            else { first = first->next; delete current; }
        else {
            current = find_prev(std::move(data));
            auto next = current->next->next;
            delete current->next;
            current->next = next;
        }
    }

    void print() {

        Node* current = first;

        while (current != nullptr) {
            std::cout << current->data << "->";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    };
    void cleanup() {

        while (first != nullptr) {
            auto next = first->next;
            delete first;
            first = next;
        }
        std::cout << "list deleted" << std::endl;
    };

};
//2.2
#include <array>
template <class T, size_t SIZE = 10>
class ouMyQueue
{
    std::array<T, SIZE>* queue_;
public:
    ouMyQueue() { queue_ = new std::array<T, SIZE>; };

public:
    struct possition {
        size_t pos;
        possition(size_t pos_) { pos = pos_; };
        possition() { pos = 0; };

        possition& operator++()
        {
            if ((pos + 1) < SIZE)++pos;
            else pos = 0;
            return *this;
        };
        possition operator++(int)
        {
            possition temp = *this;
            ++* this;
            return temp;
        };

        possition& operator--()
        {
            if (pos != 0)--pos;
            else pos = SIZE - 1;
            return *this;
        };

        possition operator--(int)
        {
            possition temp = *this;
            --* this;
            return temp;
        };

        //auto operator<=>(const possition&)const = default;

    };
private:
    possition Head_;
    possition Tail_;

    bool b_is_full = false;
    bool b_is_empty = true;
    bool b_is_one_element = false;

public:
    bool is_full() { return b_is_full; }
    bool is_empty() { return b_is_empty; }
    void push(T data)
    {
        if (is_full()) std::cout << "push failed. queue is full" << std::endl;
        else if (is_empty())
        {
            queue_->operator[](Tail_.pos) = data;
            b_is_empty = false;
            b_is_one_element = true;
        }
        else
        {
            b_is_one_element = false;
            Tail_++;
            queue_->operator[](Tail_.pos) = data;
            Tail_++;
            if (Tail_.pos == Head_.pos) b_is_full = true;
            Tail_--;
        }
    };

    T pop()
    {
        if (is_empty())std::cout << "pop failed. queue is empty" << std::endl;
        else {
            b_is_full = false;
            auto current = Head_.pos;

            if ((Tail_.pos == Head_.pos) && b_is_one_element) { b_is_empty = true; b_is_one_element = false; }
            else Head_++;

            if (Tail_.pos == Head_.pos && !b_is_one_element) { b_is_one_element = true; }
            return queue_->operator[](current);
        }
    };

    void print()
    {
        possition current(Head_.pos);
        std::array <std::string, SIZE>* print_array = new std::array <std::string, SIZE>;
        for (auto& s : *print_array)s = " ";

        if (!is_empty())
            while (true)
            {

                print_array->operator[](current.pos) = std::to_string(queue_->operator[](current.pos));
                if (b_is_one_element)break;

                current++;

                if (current.pos == Tail_.pos) {
                    print_array->operator[](current.pos) = std::to_string(queue_->operator[](current.pos));
                    break;
                };
            };
        for (size_t i = 0; i < SIZE; i++) std::cout << i << " ";
        std::cout << std::endl;

        for (size_t i = 0; i < SIZE; i++) std::cout << print_array->operator[](i) << " ";
        std::cout << std::endl;

        for (size_t i = 0; i < SIZE; i++) if (Head_.pos == i)std::cout << "H"; else std::cout << "  ";
        std::cout << std::endl;

        for (size_t i = 0; i < SIZE; i++) if (Tail_.pos == i)std::cout << "T"; else std::cout << "  ";
        std::cout << std::endl;

    };
};

#include <vector>
#include <tuple>
//2.3
template<typename T,size_t N = 10>
struct graph
{

    std::vector<T> V;
    std::vector<std::pair<T, T>> E;
    std::vector<bool> visited;
    bool first_DFS_iteration = true;
    T last_visited_node;
    int number_path_started = 0;
  
    T getLastVisitedNode() { return last_visited_node; }
    int getNumberCurrentPath() { return number_path_started;}
 
    void print() {
        std::cout << "V = { ";
        for (auto& v : V)std::cout << v << " ";
        std::cout << " }" << std::endl
            << "E = { ";
        for (auto& e : E)std::cout << "{" << e.first << "," << e.second << "} ";
        std::cout << " }" << std::endl;

    }

    std::vector<int> makeAdjacencyList(int node) {
    
        std::vector<int> vec{};
        for (auto& e : E)
        {
            if (e.first == node&&!visited[e.second])vec.push_back(e.second);
            else if (e.second == node && !visited[e.first])vec.push_back(e.first);
        }

        return std::move(vec);

    }

    void DFS_recurcive(int node, std::function<void()> visualisation_func = []{}) {
       // std::cout << "getLastVisitedNode() = " << getLastVisitedNode() << std::endl;
        if (node<0 || node>N) { std::cout << __FUNCDNAME__ << " error. first node not in range." << std::endl; }

        if (first_DFS_iteration) {
            visited.resize(N + 1);
            std::cout << "DFS_Recurcive: "<<node;
            first_DFS_iteration = false;

            for (size_t i = 0; i < visited.size(); i++)visited[i] = false;
            
        }

        visited[node] = true;

        last_visited_node = node;
        visualisation_func();

        bool bl=true;
        for (auto b : visited) { bl = b && bl; }; 
        if (bl)first_DFS_iteration = true;

        std::vector<int> AdjacencyList=makeAdjacencyList(node);
        //for (auto& a : AdjacencyList)std::cout << a << " "; std::cout << std::endl;

        for (auto& a : AdjacencyList) 
            if (!visited[a]){
                std::cout << "->" << a;
                DFS_recurcive(a, visualisation_func);}

    };
    void DFS_stack(int node, std::function<void()> visualisation_func = [] {})
    {
        if (node<0 || node>N) { std::cout <<__FUNCDNAME__<< " error. first node not in range." << std::endl; }
        std::cout << std::endl;
     
        visited.resize(N + 1);
        for (size_t i = 0; i < visited.size(); i++)visited[i] = false;
       // std::cout << "DFS_Stack:visited: "; for (auto v : visited)std::cout << v; std::cout << std::endl;
        std::cout << "DFS_Stack: " << node;
        
        ouMyStack<int,N*N> stack;
        stack.push(node);
        while (!stack.is_empty()) {
            auto c = stack.top();
            stack.pop();
            visited[c] = true;
            last_visited_node = c;
            visualisation_func();
            std::vector<int> AdjacencyList = makeAdjacencyList(c);
            for (auto& a : AdjacencyList)
            {
                if (!visited[a]) {
                std::cout << "->" << a;
                stack.push(a);}
            }
        };
    }

    void DFS_stack_2(int  node, std::function<void()> visualisation_func = [] {})
    {
        if (node<0 || node>N) { std::cout << __FUNCDNAME__ << " error. first node not in range." << std::endl; }
        std::cout << std::endl;
        std::vector<int> instack;

        instack.resize(N + 1);
        visited.resize(N + 1);

        for (size_t i = 0; i < visited.size(); i++) 
        {
            visited[i] = false; 
            instack[i] = false;
        }

        //std::cout << "DFS_stack_2:visited: "; for (auto v : visited)std::cout << v; std::cout << std::endl;
        std::cout << "DFS_stack_2: " << node;
        
        ouMyStack<int,N*N> stack;
        stack.push(node);

        instack[node] = true;

        while (!stack.is_empty()) {
            auto c = stack.top();
            stack.pop();
            instack[c] = false;
            visited[c] = true;
            last_visited_node = c;
            visualisation_func();
            std::vector<int> AdjacencyList = makeAdjacencyList(c);
            for (auto& a : AdjacencyList)
            {
                if (!visited[a]&&!instack[a]) {
                    std::cout << "->" << a;
                    stack.push(a);
                    instack[a] = true;
                }
            }
        }//while
        std::cout << std::endl;
    }

    void DFS_stack_2_random(int  node, std::function<void()> visualisation_func = [] {})
    {
        if (node<0 || node>N) { std::cout << __FUNCDNAME__ << " error. first node not in range." << std::endl; }
        std::cout << std::endl;
        std::vector<bool> instack;
        std::vector<int> not_in_visited;
        for (int i = 0; i < N; i++)not_in_visited.push_back(i);
        instack.resize(N );
        visited.resize(N );

        for (size_t i = 0; i < visited.size(); i++)
        {
            visited[i] = false;
            instack[i] = false;
        }
        
        ouMyStack<int, N*N> stack;
        stack.push(node);
        instack[node] = true;
        visited[node] = true;
        auto current = stack.top();

        auto iter = std::find(not_in_visited.begin(), not_in_visited.end(), current);
        if (iter != not_in_visited.end())
        not_in_visited.erase(iter);

        bool all_visited_true = false;
        std::vector<int> AdjacencyList = makeAdjacencyList(current);

        while(!all_visited_true){
            
        while (AdjacencyList.empty()) {
            
            current = not_in_visited[RAND(0,not_in_visited.size()-1)];

            AdjacencyList = makeAdjacencyList(current);
            if (AdjacencyList.empty())AdjacencyList.push_back(current);
            }
            

		while (!AdjacencyList.empty())
		{
            auto r = RAND(0, AdjacencyList.size() - 1); //std::cout << "AdjacencyList.size() = " << AdjacencyList.size() << " RAND(0, AdjacencyList.size()) = " << r << std::endl;
            current = AdjacencyList[r];

            auto iter = std::find(not_in_visited.begin(), not_in_visited.end(), current);
            if (iter != not_in_visited.end())
            not_in_visited.erase(iter);

            if (!visited[current] && !instack[current])
            {
                stack.push(current);
                instack[current] = true;
                AdjacencyList.clear();
                AdjacencyList = makeAdjacencyList(current);
            }
            else {
                auto iter = std::find(AdjacencyList.begin(), AdjacencyList.end(), current);
                if(iter!=AdjacencyList.end())
                AdjacencyList.erase(iter);
            }   
		};

        
        while (!stack.is_empty()) 
        {
            current = stack.top();
            visited[current] = true;
            std::cout << "->" << current;
            last_visited_node = current;
            visualisation_func();
            stack.pop();
        
            if(stack.is_empty())number_path_started++;
        }

        
        bool bl = true;
        for (auto b : visited) { bl = b && bl; };

        if (bl)all_visited_true = true;
        }
        number_path_started = 0;
        std::cout << std::endl;
    }

    void BFS(int  node, std::function<void()> visualisation_func = [] {})
    {
        std::cout << std::endl;
        std::vector<int> inqueue;

        inqueue.resize(N + 1);
        visited.resize(N + 1);

        for (size_t i = 0; i < visited.size(); i++)
        {
            visited[i] = false;
            inqueue[i] = false;
        }

        std::cout << "DFS_stack_2:visited: "; for (auto v : visited)std::cout << v; std::cout << std::endl;
        std::cout << "BFS: " << node;

        ouMyQueue<int,N> queue;
        queue.push(node);

        inqueue[node] = true;

        while (!queue.is_empty()) {
            auto c = queue.pop();
            inqueue[c] = false;
            visited[c] = true;
            last_visited_node = c;
            visualisation_func();
            std::vector<int> AdjacencyList = makeAdjacencyList(c);
            for (auto& a : AdjacencyList)
            {
                if (!visited[a] && !inqueue[a]) {
                    std::cout << "->" << a;
                    queue.push(a);
                    inqueue[a] = true;
                }
            }
        }//while
        std::cout << std::endl;
    }
   
};

template<typename T, int N = 10>
graph<T,N> generateRandomGraph() {
    graph<T,N> G;

    for (int i = 0; i <= N; i++)
    {
        G.V.push_back(i);
        G.E.push_back({ i,RAND(0,N) });
        if (RAND(0, 1000) % 2)G.E.push_back({ i,RAND(0,N) });
        if (RAND(0, 1000) % 3)G.E.push_back({ i,RAND(0,N) });
        if (RAND(0, 1000) % 5)G.E.push_back({ i,RAND(0,N) });
    }

    //remove duplicates
    std::sort(G.E.begin(), G.E.end());
    auto last = std::unique(G.E.begin(), G.E.end());
    G.E.erase(last, G.E.end());

    //remove loops
    G.E.erase(std::remove_if(G.E.begin(), G.E.end(), [](std::pair<int, int> pair) {return pair.first == pair.second; }));

    return G;
}

template<typename T,int X,int Y>
graph<T, X * Y> generateLabirinthGraph()
{
    graph<T, X * Y> G;

    for (int i = 0; i < X; i++)
        for (int j = 0; j < Y; j++)
        {
            int xy =  i*Y + j;
            G.V.push_back(xy);

            if (i == X - 1 && j == Y - 1)break;
            else if (i == X - 1)
                G.E.push_back({xy,xy+1});
            else if (j == Y - 1)
                G.E.push_back({xy,xy+Y});
            else {
                G.E.push_back({ xy, xy + 1 });
                G.E.push_back({ xy, xy + Y });
            };
        };
    return std::move(G);
}



#endif