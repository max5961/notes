import { mergeSort } from '../algorithms/mergeSort';

function isOrdered(arr: number[]): boolean {
    for (let i = 0; i < arr.length; i++) {
        const left: number = arr[i];
        const right: number = arr[i + 1];
        if (left > right) {
            return false;
        }
    }
    return true;
}

test('[] to equal []', () => {
    expect(mergeSort([])).toEqual([]);
});

test('[1] to equal [1]', () => {
    expect(mergeSort([1])).toEqual([1]);
});

test('[5,4,3,2,1] to equal [1,2,3,4,5]', () => {
    expect(mergeSort([5,4,3,2,1])).toEqual([1,2,3,4,5]);
});

test('[3,6,2,4] to equal [2,3,4,6]', () => {
    expect(mergeSort([3,6,2,4])).toEqual([2,3,4,6]);
})

test('[10,2,5,3,7,5,1] to equal [1,2,3,5,5,7,10]', () => {
    expect(mergeSort([10,2,5,3,7,5,1])).toEqual([1,2,3,5,5,7,10]);
});

test('[5,3,2,4,5,7,6,5,2] to be sorted in ascending order', () => {
    const sortedArray: number[] = mergeSort([5,3,2,4,5,7,6,5,2]);
    expect(isOrdered(sortedArray)).toBe(true);
})


