int main()
{
    int n=10;
    int res=sum(n);
    printf("res: %d", res);
}

int sum(int top)
{
    int i, s;
    s=0;
    for (i=top; i>0; i--)
    {
        s += i;
    }
    return s;
}