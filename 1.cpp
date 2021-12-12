

// 康复训练
// 为什么我们的康复训练变成了模板测试？？？
// 别问，问就是好玩

// 写得差不多了上来bb两句
// cpp确实好玩
// 我想弄个git仓库拿来放这种娱乐性的cpp代码


#include<stdio.h>
#include<malloc.h>


void PrintChar(char a)
{
    printf("%c ", a);
}

int WhichMax(char a, char b)
{
    if(a>b)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}


template<class t0>
class MyList
{
    public:

    MyList(char a[])
    {
        this->Init();
        printf("%s\n", a);
    }

    void Init()
    {
        this->datas = (t0 *)malloc(100*sizeof(t0));
        this->len = 0;
    }

    t0 GetAt(int pos)
    {
        return this->datas[pos];
    }

    void Append(t0 elem)
    {
        this->datas[this->len] = elem;
        this->len += 1;
    }

    void RemoveAt(int pos)
    {
        for(int i=pos;i<this->len-1;i++)
        {
            this->datas[i] = this->datas[i+1];
        }
        this->len -= 1;
    }

    void Destroy()
    {
        free(this->datas);
    }

    // 一个初级的map
    // 只能使用一种函数指针:接受一个t0类型的参数，没有返回值
    void _weak_Map(void(*func)(t0))
    {
        for(int i=0;i<this->len;i++)
        {
            func(this->datas[i]);
        }
    }

    // 根据任意一个函数来进行排序
    // 这个所谓的任意函数会吞入两个t0类型的元素，然后返回0（前者较大）1（后者较大）
    // 根据返回值即可推断两个值的大小
    // 默认使用冒泡
    void _weak_SortBy(int(*WhichMax)(t0, t0))
    {
        for(int i=0;i<this->len-1;i++)
        {
            for(int j=0;j<this->len-i-1;j++)
            {
                t0 *prev = &(this->datas[j]);
                t0 *next = &(this->datas[j+1]);

                int result = WhichMax(*prev, *next);

                if(result == 0)  // 前者较大，需要将前者与后者交换
                {
                    t0 temp = *prev;
                    *prev = *next;
                    *next = temp;
                }
                else
                {

                }
            }
        }
    }

    private:

    t0 *datas;
    int len = 0;
};




int main()
{
    MyList<char> a("This is an instance of MyList.\n");

    a.Append('b');
    a.Append('c');
    a.Append('a');
    a.Append('b');
    a.Append('c');
    a.Append('a');
    a.Append('b');
    a.Append('c');
    a.Append('a');

    a._weak_SortBy(*WhichMax);

    a._weak_Map(*PrintChar);
    printf("\n");
    
    printf("WhichMap('a', 'b') = %d;", WhichMax('a', 'b'));

    a.Destroy();
}
