pure int solve(int total, int[] price)
{
    int result = 0;
    foreach (int i; price)
        result += i;
    return total - result;
}

void main()
{
    import std.stdio;

    int total; readf!" %d"(total);
    int[9] price;
    foreach (ref i; price)
        readf!" %d"(i);
    
    solve(total, price).writeln;
}
