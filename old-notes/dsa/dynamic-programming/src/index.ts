import "./style/index.css";

// write a function that takes in a targetSum and array of numbers 
// the function should return array containing any combination of elements
// that add up to exactly the targetSum 
// if there is no combination that adds up to the targetSum, return null 
// if there are multiple combinations possible, return any single one

function howSumTabulation(targetSum: number, numbers: number[]): number[] | null {
    const table: number[][] | null[] = Array(targetSum).fill(null);
    table[0] = [];
    for (let i = 0; i <= targetSum; i++) {
        if (table[i]) {
            for (const num of numbers) {
                const subTotalArray: number[] = table[i]!.map(n => n);
                subTotalArray.push(num);
                table[i + num] = subTotalArray;
            }
        }
    }
    return table[targetSum];
}

// console.log (howSumTabulation(7, [5,3,4]));
// console.log(howSumTabulation(5, [1,2,1,1,1,1]));


function bestSumTabulation(targetsum: number, numbers: number[]): number[] | null {
    const table: number[][] | null[] = Array(targetsum).fill(null);
    table[0] = [];
    for (let i = 0; i <= targetsum; i++) {
        if (table[i]) {
            for (const num of numbers) {
                const subTotalArray: number[] = table[i]!.map(n => n);
                subTotalArray.push(num);
                if (!table[i + num]) {
                    table[i + num] = subTotalArray;
                } else if (table[i + num]!.length > subTotalArray.length) {
                    table[i + num] = subTotalArray;
                }
            }
        }
    }
    return table[targetsum];
}

// console.log(bestSumTabulation(5, [1,2,1,1,1,1]));

function coinChange(coins: number[], amount: number): number {
    const table: number[] = Array(amount + 1).fill(-1);
    table[0] = 1;
    for (let i = 0; i <= amount; i++) {
        if (table[i] !== -1) {
            for (const num of coins) {
                if (table[i + num] === -1 || table[i + num] === undefined) {
                    table[i + num] = 1;
                } else if (table[i + num] > table[i]) {
                    table[i + num] += table[i];
                } else {
                    table[i + num] += 1;
                }
            }
        }
    }
    return table[amount]
}

function tribonacci(n: number): number {
    if (n <= 1) return n;
    if (n === 2) return 1;
    
    const trib: number[] = [0,1,1];
    for (let i = 3; i <= n; i++) {
        trib.push(trib[i-1] + trib[i-2] + trib[i-3]); 
    }

    return trib[trib.length - 1];
}











