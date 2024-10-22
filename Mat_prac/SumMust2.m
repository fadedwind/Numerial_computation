function out1 = SumMust2(n)

    sum_n = 0;
    for i = 1:n
        sum_n = sum_n + i;
        s = sum_n * (n + 1);
    end
    out1 = s;
end
    