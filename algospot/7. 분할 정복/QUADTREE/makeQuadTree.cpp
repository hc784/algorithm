#include <iostream>
#include <string>
using namespace std;
int StrIdx=1;
string ret="";
typedef char QTData;
typedef struct _QTreeNode {
    QTData data;
    struct _QTreeNode * first;
    struct _QTreeNode * second;
    struct _QTreeNode * third;
    struct _QTreeNode * fourth;
} QTreeNode;

QTreeNode * MakeQTreeNode()
{
    QTreeNode * n = new QTreeNode;
    n->first=NULL;
    n->second=NULL;
    n->third=NULL;
    n->fourth=NULL;
    
    return n;
}

QTData GetData(QTreeNode * qt)
{
    return qt->data;
}

void SetData(QTreeNode * qt, QTData data)
{
    qt->data=data;
}

QTreeNode * GetSubTree(QTreeNode * qt, int num)
{
    switch(num)
    {
        case 1:
            return qt->first;
            break;
        case 2:
            return qt->second;
            break;
        case 3:
            return qt->third;
            break;
        case 4:
            return qt->fourth;
    }
    return NULL;
}

void MakeSubTree(QTreeNode * qt, int num)
{
    QTreeNode * nd=MakeQTreeNode();
    switch(num)
    {
        case 1:
            qt->first=nd;
            break;
        case 2:
            qt->second=nd;
            break;
        case 3:
            qt->third=nd;
            break;
        case 4:
            qt->fourth=nd;
    }
}
// 항상 w 시작 -> head는 w가 들어있는 헤드노드
void RecurInsertData(QTreeNode * head, string str, int count)
{
    // 단일은 나중에 처리 -- 단일은 재귀 말고 메인에서나 다른 함수에서 처리하기

    // if(str[0]!=w)
    // {
    //     return;
    // }
    while(count<5)
    {
        MakeSubTree(head,count);
        QTreeNode * sub = GetSubTree(head,count);
        if(str[StrIdx]=='x')
        {
            count++;
            StrIdx++;
            SetData(sub,'x');
            RecurInsertData(sub,str,1);
            continue;
        }
        
        SetData(sub,str[StrIdx]);
        count++;
        StrIdx++;
    }
}

void Traverse(QTreeNode * qt)
{
        if(GetSubTree(qt,1)!=NULL)
        {
            for(int i=1;i<5;i++)
            {
                QTreeNode * sub = GetSubTree(qt,i);
                ret+=GetData(sub);
                Traverse(sub);
            }
        }
}

QTreeNode * Insert(string str)
{
    QTreeNode * qt = MakeQTreeNode();
    if(str.size()==1)
    {
        SetData(qt,str[0]);
        return qt;
    }
    
    SetData(qt,'x');
    RecurInsertData(qt,str,1);
    
    return qt;
}

void Print(QTreeNode * qt)
{
    if(GetSubTree(qt,1)==NULL)
    {
        ret+=GetData(qt);
        return;
    }
    ret+=GetData(qt);
    Traverse(qt);
}

void SetSubTree(QTreeNode * root, QTreeNode * sub, int num)
{
    switch(num)
    {
        case 1:
            root->first=sub;
            break;
        case 2:
            root->second=sub;
            break;
        case 3:
            root->third=sub;
            break;
        case 4:
            root->fourth=sub;
    }
}

void ChangeSubTree(QTreeNode * qt)
{
    QTreeNode * temp = GetSubTree(qt,1);
    SetSubTree(qt,GetSubTree(qt,3),1);
    SetSubTree(qt,temp,3);
    
    temp = GetSubTree(qt,2);
    SetSubTree(qt,GetSubTree(qt,4),2);
    SetSubTree(qt,temp,4);
    
}

void Reverse(QTreeNode * qt)
{
    ChangeSubTree(qt);
    for(int i=1;i<5;i++)
    {
        QTreeNode * sub = GetSubTree(qt,i);
        if(GetSubTree(sub,1)!=NULL)
        {
            Reverse(sub);
        }
    }

    
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        StrIdx=1;
        string str;
        cin>>str;
        if(str.size()==1)
        {
            ret+=str+"\n";
            continue;
        }
        QTreeNode * qt = Insert(str);
        Reverse(qt);
        Print(qt);
        ret+="\n";
    }
    cout<<ret;
    
    return 0;
}
