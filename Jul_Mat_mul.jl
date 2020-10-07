n = 700;
A  = rand(0:100,n,n);
B = rand(0:100,n,n);

C = zeros(n,n);

@time begin
for i = 1:n
        C_ = 0;
        for j = 1:n
            for k = 1:n
                C[i,j] = ( A[j,k] * B[k,j] )+ C_;
            end
        end
    end
end

