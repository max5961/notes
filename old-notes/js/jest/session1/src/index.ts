import './style/index.scss';


function mergeSort(arr: number[]): number[] {
    if (arr.length < 2) {
        return arr;
    }
    const mid: number = Math.floor(arr.length / 2);
    const left: number[] = arr.slice(0, mid);
    const right: number[] = arr.slice(mid);
    return merge(mergeSort(left), mergeSort(right));
}

function merge(left: number[], right: number[]): number[] {
    const sorted: number[] = [];
    while (left.length && right.length) {
        if (left[0] > right[0]) {
            sorted.push(right.shift() as number);
        } else {
            sorted.push(left.shift() as number);
        }
    }
    return [...sorted, ...left, ...right];
}

console.log(mergeSort([5,4,3,2,1]));

