#include <gtest/gtest.h>
#include "priorityqueue.h"



/*
Syed Mehdi     UIN 651624073          NetID: smehd2
Test cases for each member function and more found in 'priorityqueue.h'
*/
TEST(priorityqueue, emptyQueue) {
    // TO DO: write lots of assertions here.
    priorityqueue<int> pq;
    string res = pq.toString();
    ASSERT_EQ(res, "");
    ASSERT_EQ(0, pq.Size());
}

TEST(enqueue, oneItem){
    priorityqueue<string> pq;
    ASSERT_EQ(0, pq.Size());
    pq.enqueue("Jermaine Cole", 1);
    string str = pq.toString();
    ASSERT_EQ(1, pq.Size())<< "Item unsucessfully enqueued";
    ASSERT_EQ("1 value: Jermaine Cole\n", str)<<"toString() failed";
}

TEST(enqueue, twoItems){
    map<int , string> mp;
    
    priorityqueue<string> pq;
    ASSERT_EQ(0, pq.Size());

    string vals[] = {"J.Cole", "Michael Jackson"};
    int pris[] = {1,2};

    for(int i = 0; i < 2; i++){
        pq.enqueue(vals[i], pris[i]);
        mp[pris[i]] = vals[i];
    }
    
    ASSERT_EQ(2, pq.Size());
    
    stringstream ss;
    for(auto e : mp){
        int priority = e.first;
        string val = e.second;
        ss<<priority<< " value: "<< val <<endl;
    }
    EXPECT_EQ(pq.toString(), ss.str());
    
}

TEST(multipleItems, noDups){
    map<int , string> mp;
    
    priorityqueue<string> pq;
    ASSERT_EQ(0, pq.Size());

    string vals[] = {"J.Cole", "Michael Jackson", "Walter White", "Saul Goodman", "Jesse Pinkman"};
    int pris[] = {3,2,1,4,5};//in random order as well

    for(int i = 0; i < 5; i++){
        pq.enqueue(vals[i], pris[i]);
        mp[pris[i]] = vals[i];
    }
    
    ASSERT_EQ(5, pq.Size());
    
    stringstream ss;
    for(auto e : mp){
        int priority = e.first;
        string val = e.second;
        ss<<priority<< " value: "<< val <<endl;
    }
    EXPECT_EQ(pq.toString(), ss.str());
}

TEST(multipleItems, dups){
    map<int , vector<string>> mp;
    
    priorityqueue<string> pq;
    ASSERT_EQ(0, pq.Size());

    string vals[] = {"J.Cole", "Michael Jackson", "Walter White", "Saul Goodman", "Jesse Pinkman"};
    int pris[] = {3,2,2,4,3};//in random order as well

    for(int i = 0; i < 5; i++){
        pq.enqueue(vals[i], pris[i]);
        mp[pris[i]].push_back(vals[i]);
    }
    
    ASSERT_EQ(5, pq.Size()) << "Duplicates not inserted correctly";
    
    stringstream ss;
    for(auto e : mp){
        int priority = e.first;
        for(auto val : e.second){
            ss<<priority<< " value: "<< val <<endl;
        }
    }
    EXPECT_EQ(pq.toString(), ss.str())<<"toString has failed";
}

TEST(multipleItems, onlyOneDup){
    map<int , vector<string>> mp;
    
    priorityqueue<string> pq;
    ASSERT_EQ(0, pq.Size());

    string vals[] = {"J.Cole", "Michael Jackson", "Walter White", "Saul Goodman", "Jesse Pinkman"};
    int pris[] = {2,2,2,2,2};//in random order as well

    for(int i = 0; i < 5; i++){
        pq.enqueue(vals[i], pris[i]);
        mp[pris[i]].push_back(vals[i]);
    }
    
    ASSERT_EQ(5, pq.Size()) << "Duplicates not inserted correctly";
    
    stringstream ss;
    for(auto e : mp){
        int priority = e.first;
        for(auto val : e.second){
            ss<<priority<< " value: "<< val <<endl;
        }
    }
    EXPECT_EQ(pq.toString(), ss.str())<<"toString has failed";
}

TEST(multipleItems, nonAscendingInsert){//inserting in non - ascending order
    map<int , vector<string>> mp;
    
    priorityqueue<string> pq;
    ASSERT_EQ(0, pq.Size());

    string vals[] = {"J.Cole", "Michael Jackson", "Walter White", "Saul Goodman", "Jesse Pinkman"};
    int pris[] = {5,3,2,1,1};//in non - ascending order

    for(int i = 0; i < 5; i++){
        pq.enqueue(vals[i], pris[i]);
        mp[pris[i]].push_back(vals[i]);
    }
    
    ASSERT_EQ(5, pq.Size()) << "Duplicates not inserted correctly";
    
    stringstream ss;
    for(auto e : mp){
        int priority = e.first;
        for(auto val : e.second){
            ss<<priority<< " value: "<< val <<endl;
        }
    }
    EXPECT_EQ(pq.toString(), ss.str())<<"toString has failed";
}

TEST(multipleItems, nonDescendingInsert){
    map<int , vector<string>> mp;
    
    priorityqueue<string> pq;
    ASSERT_EQ(0, pq.Size());

    string vals[] = {"J.Cole", "Michael Jackson", "Walter White", "Saul Goodman", "Jesse Pinkman"};
    int pris[] = {1,2,3,3,4};//in non-descending order

    for(int i = 0; i < 5; i++){
        pq.enqueue(vals[i], pris[i]);
        mp[pris[i]].push_back(vals[i]);
    }
    
    ASSERT_EQ(5, pq.Size()) << "Duplicates not inserted correctly";
    
    stringstream ss;
    for(auto e : mp){
        int priority = e.first;
        for(auto val : e.second){
            ss<<priority<< " value: "<< val <<endl;
        }
    }
    EXPECT_EQ(pq.toString(), ss.str())<<"toString has failed";
}
TEST(multipleItems, DuplicateNames){
    map<int , vector<string>> mp;
    
    priorityqueue<string> pq;
    ASSERT_EQ(0, pq.Size());

    string vals[] = {"J.Cole", "Michael Jackson", "Walter White", "Saul Goodman", "Jesse Pinkman", "J. Cole"};
    int pris[] = {1,2,3,3,4,1};

    for(int i = 0; i < 6; i++){
        pq.enqueue(vals[i], pris[i]);
        mp[pris[i]].push_back(vals[i]);
    }
    
    ASSERT_EQ(6, pq.Size()) << "Duplicates not inserted correctly";
    
    stringstream ss;
    for(auto e : mp){
        int priority = e.first;
        for(auto val : e.second){
            ss<<priority<< " value: "<< val <<endl;
        }
    }
    EXPECT_EQ(pq.toString(), ss.str())<<"toString has failed";
}

TEST(clear, noItems){
    priorityqueue<string> pq;
    ASSERT_EQ(0, pq.Size());
    ASSERT_EQ("", pq.toString());
    pq.clear();
    ASSERT_EQ(0, pq.Size());
    ASSERT_EQ("", pq.toString());

}

TEST(clear, oneItem){
    priorityqueue<string> pq;
    pq.enqueue("Jermaine Cole", 1);
    string str = pq.toString();
    ASSERT_EQ(1, pq.Size())<< "Item unsucessfully enqueued";
    ASSERT_EQ("1 value: Jermaine Cole\n", str)<<"toString() failed";

    pq.clear();
    ASSERT_EQ(0, pq.Size());
    ASSERT_EQ("", pq.toString());

}

TEST(clear, multipleItemsnoDups){
    map<int , string> mp;
    
    priorityqueue<string> pq;
    ASSERT_EQ(0, pq.Size());

    string vals[] = {"J.Cole", "Michael Jackson", "Walter White", "Saul Goodman", "Jesse Pinkman"};
    int pris[] = {3,2,1,4,5};//in random order as well

    for(int i = 0; i < 5; i++){
        pq.enqueue(vals[i], pris[i]);
        mp[pris[i]] = vals[i];
    }
    
    ASSERT_EQ(5, pq.Size());
    
    stringstream ss;
    for(auto e : mp){
        int priority = e.first;
        string val = e.second;
        ss<<priority<< " value: "<< val <<endl;
    }
    EXPECT_EQ(pq.toString(), ss.str());

    pq.clear();
    ASSERT_EQ(0, pq.Size());
    EXPECT_EQ("", pq.toString());

}

TEST(clear, multipleItemsDups){
    map<int , vector<string>> mp;
    
    priorityqueue<string> pq;
    ASSERT_EQ(0, pq.Size());

    string vals[] = {"J.Cole", "Michael Jackson", "Walter White", "Saul Goodman", "Jesse Pinkman"};
    int pris[] = {3,2,2,4,3};//in random order as well

    for(int i = 0; i < 5; i++){
        pq.enqueue(vals[i], pris[i]);
        mp[pris[i]].push_back(vals[i]);
    }
    
    ASSERT_EQ(5, pq.Size()) << "Duplicates not inserted correctly";
    
    stringstream ss;
    for(auto e : mp){
        int priority = e.first;
        for(auto val : e.second){
            ss<<priority<< " value: "<< val <<endl;
        }
    }
    EXPECT_EQ(pq.toString(), ss.str())<<"toString has failed";

    pq.clear();
    ASSERT_EQ(0, pq.Size());
    EXPECT_EQ("", pq.toString());
}

TEST(clear, only1num){
    map<int , vector<string>> mp;
    
    priorityqueue<string> pq;
    ASSERT_EQ(0, pq.Size());

    string vals[] = {"J.Cole", "Michael Jackson", "Walter White", "Saul Goodman", "Jesse Pinkman"};
    int pris[] = {2,2,2,2,2};//in random order as well

    for(int i = 0; i < 5; i++){
        pq.enqueue(vals[i], pris[i]);
        mp[pris[i]].push_back(vals[i]);
    }
    
    ASSERT_EQ(5, pq.Size()) << "Duplicates not inserted correctly";
    
    stringstream ss;
    for(auto e : mp){
        int priority = e.first;
        for(auto val : e.second){
            ss<<priority<< " value: "<< val <<endl;
        }
    }
    EXPECT_EQ(pq.toString(), ss.str())<<"toString has failed";

    pq.clear();
    ASSERT_EQ(0, pq.Size());
    EXPECT_EQ("", pq.toString());
}

TEST(clear, RightHeavyTree){
    map<int , vector<string>> mp;
    
    priorityqueue<string> pq;
    ASSERT_EQ(0, pq.Size());

    string vals[] = {"J.Cole", "Michael Jackson", "Walter White", "Saul Goodman", "Jesse Pinkman"};
    int pris[] = {1,2,3,4,5};

    for(int i = 0; i < 5; i++){
        pq.enqueue(vals[i], pris[i]);
        mp[pris[i]].push_back(vals[i]);
    }
    
    ASSERT_EQ(5, pq.Size()) << "Duplicates not inserted correctly";
    
    stringstream ss;
    for(auto e : mp){
        int priority = e.first;
        for(auto val : e.second){
            ss<<priority<< " value: "<< val <<endl;
        }
    }
    EXPECT_EQ(pq.toString(), ss.str())<<"toString has failed";

    pq.clear();
    ASSERT_EQ(0, pq.Size());
    EXPECT_EQ("", pq.toString());
}

TEST(clear, leftHeavyTree){
    map<int , vector<string>> mp;
    
    priorityqueue<string> pq;
    ASSERT_EQ(0, pq.Size());

    string vals[] = {"J.Cole", "Michael Jackson", "Walter White", "Saul Goodman", "Jesse Pinkman"};
    int pris[] = {5,4,3,2,1};//in random order as well

    for(int i = 0; i < 5; i++){
        pq.enqueue(vals[i], pris[i]);
        mp[pris[i]].push_back(vals[i]);
    }
    
    ASSERT_EQ(5, pq.Size()) << "Duplicates not inserted correctly";
    
    stringstream ss;
    for(auto e : mp){
        int priority = e.first;
        for(auto val : e.second){
            ss<<priority<< " value: "<< val <<endl;
        }
    }
    EXPECT_EQ(pq.toString(), ss.str())<<"toString has failed";

    pq.clear();
    ASSERT_EQ(0, pq.Size());
    EXPECT_EQ("", pq.toString());
}

TEST(clear, reuse1item){
    priorityqueue<string> pq;
    pq.enqueue("Jermaine Cole", 1);
    string str = pq.toString();
    ASSERT_EQ(1, pq.Size())<< "Item unsucessfully enqueued";
    ASSERT_EQ("1 value: Jermaine Cole\n", str)<<"toString() failed";

    pq.clear();
    ASSERT_EQ(0, pq.Size());
    ASSERT_EQ("", pq.toString());

    pq.enqueue("Jermaine Cole", 1);
    str = pq.toString();
    ASSERT_EQ(1, pq.Size())<< "Item unsucessfully enqueued";
    ASSERT_EQ("1 value: Jermaine Cole\n", str)<<"toString() failed";
}

TEST(clear, reuseAfterNoEnqueue){
    priorityqueue<string> pq;
    ASSERT_EQ(0, pq.Size());
    ASSERT_EQ("", pq.toString());
    pq.clear();
    ASSERT_EQ(0, pq.Size());
    ASSERT_EQ("", pq.toString());
    pq.enqueue("Jermaine Cole", 1);
    string str = pq.toString();
    ASSERT_EQ(1, pq.Size())<< "Item unsucessfully enqueued";
    ASSERT_EQ("1 value: Jermaine Cole\n", str)<<"toString() failed";
   
}
TEST(clear,reuseMultipleTimes){
    priorityqueue<string> pq;
    map<int, string> mp;
    ASSERT_EQ(0, pq.Size());
    ASSERT_EQ("", pq.toString());
    pq.clear();
    ASSERT_EQ(0, pq.Size());
    ASSERT_EQ("", pq.toString());
    pq.enqueue("Jermaine Cole", 1);
    string str = pq.toString();
    ASSERT_EQ(1, pq.Size())<< "Item unsucessfully enqueued";
    ASSERT_EQ("1 value: Jermaine Cole\n", str)<<"toString() failed";
    pq.clear();
    ASSERT_EQ(0, pq.Size());
    ASSERT_EQ("", pq.toString());
    string vals[] = {"J.Cole", "Michael Jackson", "Walter White", "Saul Goodman", "Jesse Pinkman"};
    int pris[] = {3,2,1,4,5};//in random order as well

    for(int i = 0; i < 5; i++){
        pq.enqueue(vals[i], pris[i]);
        mp[pris[i]] = vals[i];
    }
    
    ASSERT_EQ(5, pq.Size());
    
    stringstream ss;
    for(auto e : mp){
        int priority = e.first;
        string val = e.second;
        ss<<priority<< " value: "<< val <<endl;
    }
    EXPECT_EQ(pq.toString(), ss.str());

    pq.clear();
    ASSERT_EQ(0, pq.Size());
    EXPECT_EQ("", pq.toString()); 

}

TEST(equalsOperator, emptyTrees){
    priorityqueue<string> pq;
    ASSERT_EQ(0, pq.Size());
    ASSERT_EQ("", pq.toString());

    priorityqueue<string> newPq; 
    newPq = pq;

    ASSERT_EQ(0, pq.Size());
    ASSERT_EQ("", pq.toString());

    ASSERT_EQ(0, newPq.Size());
    ASSERT_EQ("", newPq.toString());
    
}

TEST(equalsOperator, enqueueOne){
    priorityqueue<string> pq;
    ASSERT_EQ(0, pq.Size());
    ASSERT_EQ("", pq.toString());
    pq.enqueue("Lionel Messi", 2);

    priorityqueue<string> newPq;
    newPq = pq;

    ASSERT_EQ(1, newPq.Size());
    ASSERT_EQ(newPq.toString(), pq.toString());
}

TEST(equalsOperator, enqueueTwoLeft){
    //left heavy enqueue
    priorityqueue<string> pq;
    ASSERT_EQ(0, pq.Size());
    ASSERT_EQ("", pq.toString());
    pq.enqueue("Lionel Messi", 2);
    pq.enqueue("Neymar Jr", 1);

    ASSERT_EQ(2, pq.Size());

    priorityqueue<string> newPq;
    newPq = pq;

    ASSERT_EQ(2, newPq.Size());
    ASSERT_EQ(newPq.toString(), pq.toString());

}

TEST(equalsOperator, enqueueTwoRight){
    priorityqueue<string> pq;
    ASSERT_EQ(0, pq.Size());
    ASSERT_EQ("", pq.toString());
    pq.enqueue("Lionel Messi", 1);
    pq.enqueue("Neymar Jr", 2);

    ASSERT_EQ(2, pq.Size());

    priorityqueue<string> newPq;
    newPq = pq;

    ASSERT_EQ(2, newPq.Size());
    ASSERT_EQ(newPq.toString(), pq.toString());
}
TEST(equalsOperator, enqueueBalanced){
    priorityqueue<string> pq;
    ASSERT_EQ(0, pq.Size());
    ASSERT_EQ("", pq.toString());
    pq.enqueue("Lionel Messi", 2);
    pq.enqueue("Neymar Jr", 1);
    pq.enqueue("Heisenberg", 3);

    ASSERT_EQ(3, pq.Size());

    priorityqueue<string> newPq;
    newPq = pq;

    ASSERT_EQ(3, newPq.Size());
    ASSERT_EQ(newPq.toString(), pq.toString());
}
TEST(equalsOperator, enqueueBalanced2){
    priorityqueue<string> pq;
    ASSERT_EQ(0, pq.Size());
    ASSERT_EQ("", pq.toString());
    pq.enqueue("Lionel Messi", 3);
    pq.enqueue("Neymar Jr", 2);
    pq.enqueue("Heisenberg", 4);
    pq.enqueue("Michael Scott", 5);
    pq.enqueue("Jim Halpert", 1);


    ASSERT_EQ(5, pq.Size());

    priorityqueue<string> newPq;
    newPq = pq;

    ASSERT_EQ(5, newPq.Size());
    ASSERT_EQ(newPq.toString(), pq.toString());
}


TEST(equalsOperator, noLinks){
    map<int , string> mp;
    
    priorityqueue<string> pq;
    ASSERT_EQ(0, pq.Size());

    string vals[] = {"J.Cole", "Michael Jackson", "Walter White", "Saul Goodman", "Jesse Pinkman"};
    int pris[] = {3,2,1,4,5};//in random order as well

    for(int i = 0; i < 5; i++){
        pq.enqueue(vals[i], pris[i]);
        mp[pris[i]] = vals[i];
    }
    
    ASSERT_EQ(5, pq.Size());
    
    stringstream ss;
    for(auto e : mp){
        int priority = e.first;
        string val = e.second;
        ss<<priority<< " value: "<< val <<endl;
    }
    EXPECT_EQ(pq.toString(), ss.str());

    priorityqueue<string> pqcopy;
    pqcopy = pq;

    EXPECT_EQ(pqcopy.toString(), pq.toString());
}

TEST(equalsOperator, duplicates1){
    map<int , vector<string>> mp;
    
    priorityqueue<string> pq;
    ASSERT_EQ(0, pq.Size());

    string vals[] = {"J.Cole", "Michael Jackson", "Walter White", "Saul Goodman", "Jesse Pinkman"};
    int pris[] = {3,2,1,1,5};//in random order as well

    for(int i = 0; i < 5; i++){
        pq.enqueue(vals[i], pris[i]);
        mp[pris[i]].push_back(vals[i]);
    }
    
    ASSERT_EQ(5, pq.Size());
    

    priorityqueue<string> pqcopy;
    pqcopy = pq;

    EXPECT_EQ(pqcopy.toString(), pq.toString());
}

TEST(equalsOperator, duplicates2){
    map<int , vector<string>> mp;
    
    priorityqueue<string> pq;
    ASSERT_EQ(0, pq.Size());

    string vals[] = {"J.Cole", "Michael Jackson", "Walter White", "Saul Goodman", "Jesse Pinkman"};
    int pris[] = {3,1,1,1,5};//in random order as well

    for(int i = 0; i < 5; i++){
        pq.enqueue(vals[i], pris[i]);
        mp[pris[i]].push_back(vals[i]);
    }
    
    ASSERT_EQ(5, pq.Size());
    

    priorityqueue<string> pqcopy;
    pqcopy = pq;

    EXPECT_EQ(pqcopy.toString(), pq.toString());
}
TEST(equalsOperator, duplicates3){
    map<int , vector<string>> mp;
    
    priorityqueue<string> pq;
    ASSERT_EQ(0, pq.Size());

    string vals[] = {"J.Cole", "Michael Jackson", "Walter White", "Saul Goodman", "Jesse Pinkman"};
    int pris[] = {1,1,1,1,1};//in random order as well

    for(int i = 0; i < 5; i++){
        pq.enqueue(vals[i], pris[i]);
        mp[pris[i]].push_back(vals[i]);
    }
    
    ASSERT_EQ(5, pq.Size());
    

    priorityqueue<string> pqcopy;
    pqcopy = pq;

    EXPECT_EQ(pqcopy.toString(), pq.toString());
    pq.clear();
    pqcopy.clear();
}

TEST(equalsOperator, largeData){
    
    //map<int , vector<string>> mp;
    priorityqueue<string> pq;
    priorityqueue<string> pqcopy;
    string vals[] = {"Walter White", "Saul Goodman", "J.Cole", "Kendrick Lamar", "Lionel Messi", "Kylian Mbappe", "Barack Obama", "George Bush", "Mike Ermentrauht", "Joe Biden", "Hillary Clinton", "Bill Clinton"};
    int pris[] = {2,4,5,1,3,5,6,1,2,5,6,7,3,4,5};
    for(int i = 0; i < 12; i++){
        pq.enqueue(vals[i], pris[i]);
        //cout<<i<<endl;
        //mp[pris[i]].push_back(vals[i]);
    }
    
    ASSERT_EQ(12, pq.Size());
    
    pqcopy = pq;

    EXPECT_EQ(pqcopy.toString(), pq.toString());


}
TEST(equalsOperator, largeData2){
    
    //map<int , vector<string>> mp;
    priorityqueue<string> pq;
    priorityqueue<string> pqcopy;
    string vals[] = {"Walter White", "Saul Goodman", "J.Cole", 
    "Kendrick Lamar", "Lionel Messi", "Kylian Mbappe", 
    "Barack Obama", "George Bush", "Mike Ermentrauht", 
    "Joe Biden", "Hillary Clinton", "Bill Clinton",
     "JB Pritzker", "Lori Lightfoot", "Rahm Emanuel"};
    int pris[] = {2,4,5,1,3,5,6,1,2,5,6,7,3,4,5};
    for(int i = 0; i < 15; i++){
        pq.enqueue(vals[i], pris[i]);
    }
    
    ASSERT_EQ(15, pq.Size());
    
    pqcopy = pq;

    EXPECT_EQ(pq.toString(), pqcopy.toString());


}

TEST(begin, emptyTree){
    priorityqueue<string> pq;
    pq.begin();
    ASSERT_EQ(NULL, pq.getCurr()->priority);
}

TEST(begin, root){
    priorityqueue<string> pq;
    pq.enqueue("Optimus Prime", 1);
    pq.begin();
    ASSERT_EQ("Optimus Prime", pq.getCurr()->value);
    ASSERT_EQ(1, pq.getCurr()->priority);
}
TEST(begin,rightEnqueue){
    priorityqueue<string> pq;
    pq.enqueue("Optimus Prime", 1);
    pq.enqueue("Bumblebee", 2);
    pq.enqueue("Megatron", 3);
    pq.begin();
    ASSERT_EQ("Optimus Prime", pq.getCurr()->value);
    ASSERT_EQ(1, pq.getCurr()->priority);
}
TEST(begin, leftEnqueue){
    priorityqueue<string> pq;
    pq.enqueue("Optimus Prime", 3);
    pq.enqueue("Bumblebee", 2);
    pq.enqueue("Megatron", 1);
    pq.begin();
    ASSERT_EQ("Megatron", pq.getCurr()->value);
    ASSERT_EQ(1, pq.getCurr()->priority);
}
TEST(begin, smallBalanced){
    priorityqueue<string> pq;
    pq.enqueue("Optimus Prime", 2);
    pq.enqueue("Bumblebee", 3);
    pq.enqueue("Megatron", 1);
    pq.begin();
    ASSERT_EQ("Megatron", pq.getCurr()->value);
    ASSERT_EQ(1, pq.getCurr()->priority);
}
TEST(begin, largeBalanced){
    map<int , string> mp;
    
    priorityqueue<string> pq;
    ASSERT_EQ(0, pq.Size());

    string vals[] = {"J.Cole", "Michael Jackson", "Walter White", "Saul Goodman", "Jesse Pinkman"};
    int pris[] = {3,2,1,4,5};

    for(int i = 0; i < 5; i++){
        pq.enqueue(vals[i], pris[i]);
        mp[pris[i]] = vals[i];
    }
    
    ASSERT_EQ(5, pq.Size());
    
    pq.begin();
    ASSERT_EQ("Walter White", pq.getCurr()->value);
    ASSERT_EQ(1, pq.getCurr()->priority);
    
}
TEST(begin, oneDuplicate){
    map<int , vector<string>> mp;
    
    priorityqueue<string> pq;
    ASSERT_EQ(0, pq.Size());

    string vals[] = {"J.Cole", "Michael Jackson", "Walter White", "Saul Goodman", "Jesse Pinkman"};
    int pris[] = {3,2,1,1,5};

    for(int i = 0; i < 5; i++){
        pq.enqueue(vals[i], pris[i]);
        mp[pris[i]].push_back(vals[i]);
    }
    
    ASSERT_EQ(5, pq.Size());
    
    pq.begin();
    ASSERT_EQ("Walter White", pq.getCurr()->value);
    ASSERT_EQ(1, pq.getCurr()->priority);   
}
TEST(begin, multipleDuplicates){
    map<int , vector<string>> mp;
    
    priorityqueue<string> pq;
    ASSERT_EQ(0, pq.Size());

    string vals[] = {"J.Cole", "Michael Jackson", "Walter White", "Saul Goodman", "Jesse Pinkman"};
    int pris[] = {3,1,1,1,5};

    for(int i = 0; i < 5; i++){
        pq.enqueue(vals[i], pris[i]);
        mp[pris[i]].push_back(vals[i]);
    }
    
    ASSERT_EQ(5, pq.Size());
    
    pq.begin();
    ASSERT_EQ("Michael Jackson", pq.getCurr()->value);
    ASSERT_EQ(1, pq.getCurr()->priority);   
}
TEST(begin, rootwithduplicates){
    map<int , vector<string>> mp;
    
    priorityqueue<string> pq;
    ASSERT_EQ(0, pq.Size());

    string vals[] = {"J.Cole", "Michael Jackson", "Walter White", "Saul Goodman", "Jesse Pinkman"};
    int pris[] = {1,1,1,1,1};

    for(int i = 0; i < 5; i++){
        pq.enqueue(vals[i], pris[i]);
        mp[pris[i]].push_back(vals[i]);
    }
    
    ASSERT_EQ(5, pq.Size());
    
    pq.begin();
    ASSERT_EQ("J.Cole", pq.getCurr()->value);
    ASSERT_EQ(1, pq.getCurr()->priority); 
}

TEST(next, empty){
    priorityqueue<string> pq;
    pq.begin();
    ASSERT_EQ(NULL, pq.getCurr()->priority);
    string value = "";
    int priority = -1;

    bool check = pq.next(value, priority);
    ASSERT_EQ("", value);
    ASSERT_EQ(-1, priority);
    ASSERT_EQ(false, check);
    
}

TEST(next, oneNode){//should return false as there is no next
    priorityqueue <string> pq;
    pq.enqueue("Barcelona", 1);
    pq.begin();
    ASSERT_EQ(pq.getCurr()->value, "Barcelona");
    int priority = 0;
    string val = "";
    bool check = pq.next(val, priority);
    ASSERT_EQ(check, false);
    ASSERT_EQ("Barcelona", val);
    ASSERT_EQ(1, priority);
    ASSERT_EQ(nullptr, pq.getCurr());
}
TEST(next, twoNodeLeft){//one left child
    priorityqueue <string> pq;
    pq.enqueue("Barcelona", 2);
    pq.enqueue("Madrid", 1);
    pq.begin();
    ASSERT_EQ(pq.getCurr()->value, "Madrid");
    int priority = 0;
    string val = "";
    bool check = pq.next(val, priority);
    ASSERT_EQ(check, true);
    ASSERT_EQ("Madrid", val);
    ASSERT_EQ(1, priority);
    ASSERT_EQ("Barcelona", pq.getCurr()->value);
}
TEST(next, twoNodeRight){//one right child
    priorityqueue <string> pq;
    pq.enqueue("Barcelona", 1);
    pq.enqueue("Madrid", 2);
    pq.begin();
    ASSERT_EQ(pq.getCurr()->value, "Barcelona");
    int priority = 0;
    string val = "";
    bool check = pq.next(val, priority);
    ASSERT_EQ(check, true);
    ASSERT_EQ("Barcelona", val);
    ASSERT_EQ(1, priority);
    ASSERT_EQ("Madrid", pq.getCurr()->value);
    ASSERT_EQ(2, pq.getCurr()->priority);
}
TEST(next, balanced){//three items in the tree
    priorityqueue <string> pq;
    pq.enqueue("Walter White", 2);
    pq.enqueue("Saul Goodman", 1);
    pq.enqueue("Jesse Pinkman", 3);
    pq.begin();
    ASSERT_EQ("Saul Goodman", pq.getCurr()->value);
    string value = "";
    int priority = 0;
    bool check = pq.next(value, priority);
    ASSERT_EQ(check, true);
    ASSERT_EQ("Saul Goodman", value);
    ASSERT_EQ("Walter White", pq.getCurr()->value);
    ASSERT_EQ(1, priority);
    ASSERT_EQ(2, pq.getCurr()->priority);

}
TEST(next, balancedTwoNexts){//more than one next
    priorityqueue <string> pq;
    pq.enqueue("Walter White", 2);
    pq.enqueue("Saul Goodman", 1);
    pq.enqueue("Jesse Pinkman", 3);
    pq.begin();
    ASSERT_EQ("Saul Goodman", pq.getCurr()->value);
    string value = "";
    int priority = 0;
    bool check = pq.next(value, priority);
    ASSERT_EQ(check, true);
    ASSERT_EQ("Saul Goodman", value);
    ASSERT_EQ("Walter White", pq.getCurr()->value);
    ASSERT_EQ(1, priority);
    ASSERT_EQ(2, pq.getCurr()->priority);
    check = pq.next(value, priority);
    ASSERT_EQ(check, true);
    ASSERT_EQ("Walter White", value);
    ASSERT_EQ(2, priority);
    ASSERT_EQ("Jesse Pinkman", pq.getCurr()->value);
    ASSERT_EQ(3, pq.getCurr()->priority);

}
TEST(next, balancedFourNexts){//goes through whole tree
    priorityqueue <string> pq;
    pq.enqueue("Walter White", 2);
    pq.enqueue("Saul Goodman", 1);
    pq.enqueue("Jesse Pinkman", 3);
    pq.begin();
    ASSERT_EQ("Saul Goodman", pq.getCurr()->value);
    string value = "";
    int priority = 0;
    bool check = pq.next(value, priority);
    ASSERT_EQ(check, true);
    ASSERT_EQ("Saul Goodman", value);
    ASSERT_EQ("Walter White", pq.getCurr()->value);
    ASSERT_EQ(1, priority);
    ASSERT_EQ(2, pq.getCurr()->priority);
    check = pq.next(value, priority);
    ASSERT_EQ(check, true);
    ASSERT_EQ("Walter White", value);
    ASSERT_EQ(2, priority);
    ASSERT_EQ("Jesse Pinkman", pq.getCurr()->value);
    ASSERT_EQ(3, pq.getCurr()->priority);
    check = pq.next(value, priority);
    ASSERT_EQ(check, false);
    ASSERT_EQ("Jesse Pinkman", value);
    ASSERT_EQ(3, priority);
    ASSERT_EQ(nullptr, pq.getCurr());
    check = pq.next(value, priority);
    ASSERT_EQ(check, false);
}
TEST(next, dups){//next with duplicates
    priorityqueue<string> pq;
    string vals[] = {"J.Cole", "Michael Jackson", "Walter White", "Saul Goodman", "Jesse Pinkman"};
    int pris[] = {3,1,1,1,5};

    for(int i = 0; i < 5; i++){
        pq.enqueue(vals[i], pris[i]);
        //mp[pris[i]].push_back(vals[i]);
    }
    pq.begin();
    string value = "";
    int priority = 0;

    bool check = pq.next(value, priority);
    ASSERT_EQ(check, true);
    ASSERT_EQ("Michael Jackson", value);
    ASSERT_EQ(1, priority);
}

TEST(next, dups2){//checks next on a node with duplicates
    priorityqueue<string> pq;
    string vals[] = {"J.Cole", "Michael Jackson", "Walter White", "Saul Goodman", "Jesse Pinkman"};
    int pris[] = {3,1,1,1,5};

    for(int i = 0; i < 5; i++){
        pq.enqueue(vals[i], pris[i]);
        //mp[pris[i]].push_back(vals[i]);
    }
    pq.begin();
    string value = "";
    int priority = 0;

    bool check = pq.next(value, priority);
    ASSERT_EQ(check, true);
    ASSERT_EQ("Michael Jackson", value);
    ASSERT_EQ(1, priority);

    check = pq.next(value, priority);
    ASSERT_EQ(check, true);
    ASSERT_EQ("Walter White", value);
    ASSERT_EQ(1, priority);

}
TEST(next, afterLinkedList){//checks next after being at the end of linked list
    priorityqueue<string> pq;
    string vals[] = {"J.Cole", "Michael Jackson", "Walter White", "Saul Goodman", "Jesse Pinkman"};
    int pris[] = {3,1,1,1,5};

    for(int i = 0; i < 5; i++){
        pq.enqueue(vals[i], pris[i]);
        //mp[pris[i]].push_back(vals[i]);
    }
    pq.begin();
    string value = "";
    int priority = 0;
    bool check = pq.next(value, priority);
    ASSERT_EQ(check, true);
    ASSERT_EQ("Michael Jackson", value);
    ASSERT_EQ(1, priority);
    check = pq.next(value, priority);
    ASSERT_EQ(check, true);
    ASSERT_EQ("Walter White", value);
    ASSERT_EQ(1, priority);
    check = pq.next(value,priority);
    check = pq.next(value, priority);
    ASSERT_EQ(value, "J.Cole");
    ASSERT_EQ(priority, 3);
}
TEST(next, largeData){//loops through whole tree and checks if next is correct
    priorityqueue<string> pq;
    string vals[] = {"Walter White", "Saul Goodman", "J.Cole", 
    "Kendrick Lamar", "Lionel Messi", "Kylian Mbappe", 
    "Barack Obama", "George Bush", "Mike Ermentrauht", 
    "Joe Biden", "Hillary Clinton", "Bill Clinton",
     "JB Pritzker", "Lori Lightfoot", "Rahm Emanuel"};
    int pris[] = {2,4,5,1,3,5,6,1,2,5,6,7,3,4,5};
    for(int i = 0; i < 15; i++){
        pq.enqueue(vals[i], pris[i]);
    }
    
    ASSERT_EQ(15, pq.Size());

    pq.begin();
    ASSERT_EQ("Kendrick Lamar", pq.getCurr()->value);
    string value;
    int priority;
    string curVal;
    int curPriority;
    curVal = pq.getCurr()->value;
    curPriority = pq.getCurr()->priority;
    while(pq.next(value,priority)){
        ASSERT_EQ(curVal, value);
        ASSERT_EQ(curPriority, priority);
        curVal = pq.getCurr()->value;
        curPriority = pq.getCurr()->priority;
    }
}
TEST(dequeue, oneItem){//one thing in the tree
    priorityqueue<string>pq;
    pq.enqueue("Saul", 1);
    string val = pq.dequeue();
    ASSERT_EQ(val, "Saul");
    ASSERT_EQ(0, pq.Size());
}
TEST(dequeue, twoItemsLeft){//one left child
    priorityqueue<string> pq;
    pq.enqueue("Walter", 2);
    pq.enqueue("Saul", 1);
    string val = pq.dequeue();
    ASSERT_EQ(val, "Saul");
}
TEST(dequeue, twoItemsRight){//one right child
    priorityqueue<string> pq;
    pq.enqueue("Walter", 1);
    pq.enqueue("Saul", 2);
    string val = pq.dequeue();
    ASSERT_EQ(val, "Walter");
}
/*TEST(dequeue, empty){
    priorityqueue<string> pq;
    string val = pq.dequeue();
    //throws out of range

}*/

TEST(dequeue, leftHeavy){//left heavy tree
    priorityqueue<string> pq;
    pq.enqueue("Kendrick Lamar", 5);
    pq.enqueue("J.Cole", 4);
    pq.enqueue("Lebron James", 2);
    pq.enqueue("Derrick Rose",3);
    string val = pq.dequeue();
    ASSERT_EQ(pq.getCurr()->value, "Derrick Rose");
    ASSERT_EQ("Lebron James", val);
}

TEST(dequeue, leftHeavy2){//left heavy  trees
    priorityqueue<string> pq;
    pq.enqueue("Kendrick Lamar", 5);
    pq.enqueue("J.Cole", 4);
    pq.enqueue("Lebron James", 2);
    pq.enqueue("Derrick Rose",3);
    string val = pq.dequeue();
    ASSERT_EQ(pq.getCurr()->value, "Derrick Rose");
    ASSERT_EQ("Lebron James", val);
    val = pq.dequeue();
    ASSERT_EQ("J.Cole", pq.getCurr()->value);
    ASSERT_EQ("Derrick Rose", val);
}

TEST(dequeue, sizeAfterDequeue){//check for size after dequeues
    priorityqueue<string> pq;
    pq.enqueue("Kendrick Lamar", 5);
    pq.enqueue("J.Cole", 4);
    pq.enqueue("Lebron James", 2);
    pq.enqueue("Derrick Rose",3);
    ASSERT_EQ(4, pq.Size());
    string val = pq.dequeue();
    ASSERT_EQ(3, pq.Size());
    ASSERT_EQ(pq.getCurr()->value, "Derrick Rose");
    ASSERT_EQ("Lebron James", val);
    val = pq.dequeue();
    ASSERT_EQ(2, pq.Size());
    ASSERT_EQ("J.Cole", pq.getCurr()->value);
    ASSERT_EQ("Derrick Rose", val);
}

TEST(dequeue, rightHeavy){//root only has right child
    priorityqueue<string> pq;
    pq.enqueue("Kendrick Lamar", 1);
    pq.enqueue("J.Cole", 3);
    pq.enqueue("Lebron James", 4);
    pq.enqueue("Derrick Rose",2);
    ASSERT_EQ(4, pq.Size());
    string val = pq.dequeue();
    ASSERT_EQ("Kendrick Lamar", val);
    ASSERT_EQ("Derrick Rose", pq.getCurr()->value);
    ASSERT_EQ(3, pq.Size());
}
TEST(dequeue, dups){//duplicates in the root
    priorityqueue<string> pq;
    pq.enqueue("Kendrick Lamar", 1);
    pq.enqueue("J.Cole", 1);
    pq.enqueue("Lebron James", 4);
    pq.enqueue("Derrick Rose",2);
    ASSERT_EQ(4, pq.Size());
    string val = pq.dequeue();
    ASSERT_EQ("Kendrick Lamar", val);
    ASSERT_EQ("J.Cole", pq.getCurr()->value);
    ASSERT_EQ(3, pq.Size());
}
TEST(dequeue, dups2){//duplicates in the root
    priorityqueue<string> pq;
    pq.enqueue("Kendrick Lamar", 1);
    pq.enqueue("J.Cole", 1);
    pq.enqueue("Lebron James", 4);
    pq.enqueue("Derrick Rose",2);
    ASSERT_EQ(4, pq.Size());
    string val = pq.dequeue();
    ASSERT_EQ("Kendrick Lamar", val);
    ASSERT_EQ("J.Cole", pq.getCurr()->value);
    ASSERT_EQ(3, pq.Size());
    val = pq.dequeue();
    ASSERT_EQ("J.Cole", val);
    ASSERT_EQ(2, pq.Size());
    ASSERT_EQ("Derrick Rose", pq.getCurr()->value);
}

TEST(dequeue, dups3){//duplicates in a leaf
    priorityqueue<string> pq;
    string vals[] = {"J.Cole", "Michael Jackson", "Walter White", "Saul Goodman", "Jesse Pinkman"};
    int pris[] = {3,1,1,1,5};

    for(int i = 0; i < 5; i++){
        pq.enqueue(vals[i], pris[i]);
        //mp[pris[i]].push_back(vals[i]);
    }
    ASSERT_EQ(5, pq.Size());
    pq.begin();
    string val = pq.dequeue();
    ASSERT_EQ("Michael Jackson", val);
    ASSERT_EQ(4, pq.Size());
    ASSERT_EQ("Walter White", pq.getCurr()->value);
}

TEST(dequeue, largeData){//dequeues once in a large data set
    priorityqueue<string> pq;
    string vals[] = {"Walter White", "Saul Goodman", "J.Cole", 
    "Kendrick Lamar", "Lionel Messi", "Kylian Mbappe", 
    "Barack Obama", "George Bush", "Mike Ermentrauht", 
    "Joe Biden", "Hillary Clinton", "Bill Clinton",
     "JB Pritzker", "Lori Lightfoot", "Rahm Emanuel"};
    int pris[] = {2,4,5,1,3,5,6,1,2,5,6,7,3,4,5};
    for(int i = 0; i < 15; i++){
        pq.enqueue(vals[i], pris[i]);
    }
    
    ASSERT_EQ(15, pq.Size());
    string val = pq.dequeue();
    ASSERT_EQ("Kendrick Lamar", val);
    ASSERT_EQ(14, pq.Size());
}
TEST(dequeue, largeData2){//dequeues twice
    priorityqueue<string> pq;
    string vals[] = {"Walter White", "Saul Goodman", "J.Cole", 
    "Kendrick Lamar", "Lionel Messi", "Kylian Mbappe", 
    "Barack Obama", "George Bush", "Mike Ermentrauht", 
    "Joe Biden", "Hillary Clinton", "Bill Clinton",
     "JB Pritzker", "Lori Lightfoot", "Rahm Emanuel"};
    int pris[] = {2,4,5,1,3,5,6,1,2,5,6,7,3,4,5};
    for(int i = 0; i < 15; i++){
        pq.enqueue(vals[i], pris[i]);
    }
    
    ASSERT_EQ(15, pq.Size());
    string val = pq.dequeue();
    ASSERT_EQ("Kendrick Lamar", val);
    ASSERT_EQ(14, pq.Size());
    val = pq.dequeue();
    ASSERT_EQ("George Bush", val);
    ASSERT_EQ(13, pq.Size());
    ASSERT_EQ("Walter White", pq.getCurr()->value);
}
TEST(dequeue, forLoop){//loops through whole tree
    priorityqueue<string> pq;
    map<int, vector<string>> mp;
    string vals[] = {"Walter White", "Saul Goodman", "J.Cole", 
    "Kendrick Lamar", "Lionel Messi", "Kylian Mbappe", 
    "Barack Obama", "George Bush", "Mike Ermentrauht", 
    "Joe Biden", "Hillary Clinton", "Bill Clinton",
     "JB Pritzker", "Lori Lightfoot", "Rahm Emanuel"};
    int pris[] = {2,4,5,1,3,5,6,1,2,5,6,7,3,4,5};
    string val;
    for(int i = 0; i < 15; i++){
        pq.enqueue(vals[i], pris[i]);
        mp[pris[i]].push_back(vals[i]);
    }
    for(auto e: mp){
        for(string x: e.second){
            val = pq.dequeue();
            ASSERT_EQ(val, x);
        }
    }
}
TEST(peek, oneItem){//peeks when there is one item
    priorityqueue<string> pq;
    pq.enqueue("Barack Obama", 3);
    string val = pq.peek();
    ASSERT_EQ("Barack Obama", val);
}
TEST(peek, multipleItem1){
    priorityqueue<string> pq;
    pq.enqueue("Kendrick Lamar", 1);
    pq.enqueue("J.Cole", 1);
    pq.enqueue("Lebron James", 4);
    pq.enqueue("Derrick Rose",2);
    string val = pq.peek();
    ASSERT_EQ("Kendrick Lamar", val);
}
TEST(peek, largeData){
    priorityqueue<string> pq;
    string vals[] = {"Walter White", "Saul Goodman", "J.Cole", 
    "Kendrick Lamar", "Lionel Messi", "Kylian Mbappe", 
    "Barack Obama", "George Bush", "Mike Ermentrauht", 
    "Joe Biden", "Hillary Clinton", "Bill Clinton",
     "JB Pritzker", "Lori Lightfoot", "Rahm Emanuel"};
    int pris[] = {2,4,5,1,3,5,6,1,2,5,6,7,3,4,5};
    for(int i = 0; i < 15; i++){
        pq.enqueue(vals[i], pris[i]);
        //mp[pris[i]].push_back(vals[i]);
    }
    string val = pq.peek();
    ASSERT_EQ("Kendrick Lamar", val);

}
TEST(peekAndDequeue, oneItem){
    priorityqueue<string> pq;
    pq.enqueue("Barack Obama", 3);
    string val = pq.peek();
    string dequeue = pq.dequeue();
    ASSERT_EQ(val, dequeue);
}
TEST(peekAndDequeue, rightHeavy){
    priorityqueue<string> pq;
    pq.enqueue("Kendrick Lamar", 1);
    pq.enqueue("J.Cole", 3);
    pq.enqueue("Lebron James", 4);
    pq.enqueue("Derrick Rose",2);
    string val1 = pq.peek();
    string val2 = pq.dequeue();
    ASSERT_EQ(val1, val2);
}
TEST(peekAndDequeue, rightHeavy2){
    priorityqueue<string> pq;
    pq.enqueue("Kendrick Lamar", 1);
    pq.enqueue("J.Cole", 3);
    pq.enqueue("Lebron James", 4);
    pq.enqueue("Derrick Rose",2);
    string val1 = pq.peek();
    string val2 = pq.dequeue();
    ASSERT_EQ(val1, val2);
    val1 = pq.peek();
    ASSERT_EQ("Derrick Rose", val1);
}
TEST(peekAndDequeue, rightHeavy3){
    priorityqueue<string> pq;
    pq.enqueue("Kendrick Lamar", 1);
    pq.enqueue("J.Cole", 3);
    pq.enqueue("Lebron James", 4);
    pq.enqueue("Derrick Rose",2);
    string val1 = pq.peek();
    string val2 = pq.dequeue();
    ASSERT_EQ(val1, val2);
    val1 = pq.peek();
    ASSERT_EQ("Derrick Rose", val1);
    val2 = pq.dequeue();
    ASSERT_EQ(val1, val2);
}
TEST(peekAndDequeue, leftHeavy){
    priorityqueue<string> pq;
    string vals[] = {"J.Cole", "Michael Jackson", "Walter White", "Saul Goodman", "Jesse Pinkman"};
    int pris[] = {5,3,2,1,1};
    for(int i = 0; i < 5; i++){
        pq.enqueue(vals[i], pris[i]);
    }
    string val1= pq.peek();
    string val2 = pq.dequeue();
    ASSERT_EQ(val1, val2);
    val1 = pq.peek();
    val2 = pq.dequeue();
    ASSERT_EQ(val1, val2);

}
TEST(peekAndDequeue, largeData){
    priorityqueue<string> pq;
    string vals[] = {"Walter White", "Saul Goodman", "J.Cole", 
    "Kendrick Lamar", "Lionel Messi", "Kylian Mbappe", 
    "Barack Obama", "George Bush", "Mike Ermentrauht", 
    "Joe Biden", "Hillary Clinton", "Bill Clinton",
     "JB Pritzker", "Lori Lightfoot", "Rahm Emanuel"};
    int pris[] = {2,4,5,1,3,5,6,1,2,5,6,7,3,4,5};
    for(int i = 0; i < 15; i++){
        pq.enqueue(vals[i], pris[i]);
        //mp[pris[i]].push_back(vals[i]);
    }
    string val1, val2;
    while(pq.Size() != 0){
        val1 = pq.peek();
        val2 = pq.dequeue();
        ASSERT_EQ(val1, val2);
    }
}
TEST(equality, emptyTrees){
    priorityqueue<string> pq;
    priorityqueue<string> pqq;
    ASSERT_TRUE(pq == pqq);
}
TEST(equality, oneItem){
    priorityqueue<string> pq;
    priorityqueue<string> pqq;
    pq.enqueue("J.Cole", 1);
    pqq.enqueue("J.Cole", 2);
    ASSERT_FALSE(pq == pqq);
}
TEST(equality, differentShape){
    priorityqueue<string> pq;
    priorityqueue<string> pqq;
    pq.enqueue("Messi", 2);
    pq.enqueue("J.Cole", 1);
    pqq.enqueue("J.Cole", 1);
    pqq.enqueue("Messi", 2);
    ASSERT_FALSE(pqq == pq);
}
TEST(equality, differentShape2){
    priorityqueue<string> pq;
    priorityqueue<string> pqq;
    pq.enqueue("Grinch", 3);
    pq.enqueue("Messi", 2);
    pq.enqueue("J.Cole", 1);
    pqq.enqueue("J.Cole", 1);
    pqq.enqueue("Messi", 2);
    pqq.enqueue("Grinch", 3);
    ASSERT_FALSE(pqq == pq);
}
TEST(equality, copy){
    priorityqueue<string> pq;
    priorityqueue<string> pqq;
    string vals[] = {"Walter White", "Saul Goodman", "J.Cole", 
    "Kendrick Lamar", "Lionel Messi", "Kylian Mbappe", 
    "Barack Obama", "George Bush", "Mike Ermentrauht", 
    "Joe Biden", "Hillary Clinton", "Bill Clinton",
     "JB Pritzker", "Lori Lightfoot", "Rahm Emanuel"};
    int pris[] = {2,4,5,1,3,5,6,1,2,5,6,7,3,4,5};
    for(int i = 0; i < 15; i++){
        pq.enqueue(vals[i], pris[i]);
        //mp[pris[i]].push_back(vals[i]);
    }
    pqq = pq;
    ASSERT_TRUE(pq == pqq);
}
TEST(equality, switchedDuplicateRoot){
    priorityqueue<string> pq;
    priorityqueue<string> pqq;
    pq.enqueue("Messi", 1);
    pq.enqueue("Walter", 1);
    pqq.enqueue("Walter", 1);
    pqq.enqueue("Messi", 1);
    ASSERT_FALSE(pqq == pq);
}
TEST(equality, afterDequeue){
    priorityqueue<string> pq;
    priorityqueue<string> pqq;
    string vals[] = {"Walter White", "Saul Goodman", "J.Cole", 
    "Kendrick Lamar", "Lionel Messi", "Kylian Mbappe", 
    "Barack Obama", "George Bush", "Mike Ermentrauht", 
    "Joe Biden", "Hillary Clinton", "Bill Clinton",
     "JB Pritzker", "Lori Lightfoot", "Rahm Emanuel"};
    int pris[] = {2,4,5,1,3,5,6,1,2,5,6,7,3,4,5};
    for(int i = 0; i < 15; i++){
        pq.enqueue(vals[i], pris[i]);
        //mp[pris[i]].push_back(vals[i]);
    }
    pqq = pq;
    ASSERT_TRUE(pq == pqq);
    pq.dequeue();
    pqq.dequeue();
    ASSERT_TRUE(pq == pqq);
    pq.dequeue();
    ASSERT_FALSE(pq == pqq);
}
