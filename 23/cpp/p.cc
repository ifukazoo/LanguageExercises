#include <iostream>

class DecisionNode {

private:
    std::string message_;
    DecisionNode* yes_;
    DecisionNode*  no_;

    bool has_next() const {
        return yes_ && no_;
    }

public:
    DecisionNode(std::string message)
        : message_(message)
          , yes_(nullptr)
          , no_(nullptr) {}

    void do_work() const {
        if (has_next()) {
            std::cout <<  message_ ;

            std::string input;
            std::getline(std::cin, input);
            auto c = std::toupper(input.at(0));
            switch (c) {
            case 'Y':
                yes_->do_work();
                break;
            case 'N':
                no_->do_work();
                break;
            default:
                break;
            }
        } else {
            std::cout <<  message_ << std::endl;
        }
    }
    void set_yes(DecisionNode* yes) {
        yes_ = yes;
    }
    void set_no(DecisionNode* no) {
        no_ = no;
    }
};


int main()
{
    DecisionNode* q1  = new DecisionNode("Is the car silent when you turn the key? ");
    DecisionNode* q2  = new DecisionNode("Are the battery terminals corroded? ");
    DecisionNode* q3  = new DecisionNode("Does the car make a clicking noise? ");
    DecisionNode* q4  = new DecisionNode("Clean terminals and try starting again.");
    DecisionNode* q5  = new DecisionNode("Replace cables and try again.");
    DecisionNode* q6  = new DecisionNode("Replace the battery.");
    DecisionNode* q7  = new DecisionNode("Does the car crank up but fail to start? ");
    DecisionNode* q8  = new DecisionNode("Check spark plug connections.");
    DecisionNode* q9  = new DecisionNode("Does the engine start and then die? ");
    DecisionNode* q10 = new DecisionNode("Does your car have fuel injection? ");
    DecisionNode* q11 = new DecisionNode("Check to ensure the choke is opening and closing.");
    DecisionNode* q12 = new DecisionNode("Get it in for service.");

    q1->set_yes(q2);
    q1->set_no(q3);

    q2->set_yes(q4);
    q2->set_no(q5);

    q3->set_yes(q6);
    q3->set_no(q7);

    q7->set_yes(q8);
    q7->set_no(q9);

    q9->set_yes(q10);
    q9->set_no(q12); // not exists.

    q10->set_no(q11);
    q10->set_yes(q12);

    q1->do_work();

    return 0;
}
