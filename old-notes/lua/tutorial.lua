-- the dofile function immediately executes a file and then allows
-- you to run chunks or functions within the file
-- in terminal:
-- lua -i
-- dofile('filename')
-- print(fact(5))

function fact (n)
    if n == 0 then
        return 1
    else
        return n * fact(n - 1)
    end
end

days = {"Sunday", "Monday", "Tuesday", "Wednesday"};









