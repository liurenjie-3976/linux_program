#include <iostream>

using namespace std;
// 结构结点
struct Node
{
    int data;
    Node *next;
};

class Queue
{
    private:
        Node *front;//头指针
        Node *rear;//队尾指针

    public:
        Queue(){
            front = rear = nullptr;//初始化队列和队尾指针为空指针
        }

        bool isEmpty(){
            return front == nullptr;//判断队列是否为空
        }

        void enqueue(int data){
            Node *newNode = new Node;//创建新结点
            newNode->data = data;//为新结点赋值
            newNode->next = nullptr;//新结点的指针域为空
            if(isEmpty()){//如果队列为空
                front = rear = newNode;//队列头指针和队尾指针都指向新结点
            }else{
                rear->next = newNode;//队尾指针的指针域指向新结点
                rear = newNode;//队尾指针指向新结点
            }
        }

        void dequeue(){
            if(isEmpty()){//如果队列为空
                cout << "队列为空" << endl;
                
            }else{
                Node *temp = front;//创建临时指针指向队列头指针
                front = front->next;//队列头指针指向下一个结点
                delete temp;//删除临时指针,释放内存。
            }
        }

        int getFront(){
            if(isEmpty()){//如果队列为空
                cout << "队列为空" << endl;
                return -1;
            }else{
                return front->data;//返回队列头指针的值
            }
        }


};

int main()
{
    Queue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    // cout << "队列头元素为：" << queue.getFront() << endl;
    // queue.dequeue();
    // cout << "队列头元素为：" << queue.getFront() << endl;
    // queue.dequeue();
    // cout << "队列头元素为：" << queue.getFront() << endl;
    // queue.dequeue();
    // cout << "队列头元素为：" << queue.getFront() << endl;
    // queue.dequeue();
    // cout << "队列头元素为：" << queue.getFront() << endl;
    while(!queue.isEmpty()){
        cout << "队列头元素为：" << queue.getFront() << endl;
        queue.dequeue();
    }
    return 0;
}
