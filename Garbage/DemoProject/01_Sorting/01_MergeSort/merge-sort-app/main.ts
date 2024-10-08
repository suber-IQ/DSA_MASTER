document.getElementById('sort-form')!.addEventListener('submit', function (event) {
    event.preventDefault();
    const input = (document.getElementById('array-input') as HTMLInputElement).value;
    const array = input.split(',').map(Number);
    const sortedArray = mergeSort(array);
    displayResult(sortedArray);
});

function mergeSort(arr: number[]): number[] {
    if (arr.length <= 1) {
        return arr;
    }
    
    const middle = Math.floor(arr.length / 2);
    const left = arr.slice(0, middle);
    const right = arr.slice(middle);

    return merge(mergeSort(left), mergeSort(right));
}

function merge(left: number[], right: number[]): number[] {
    let resultArray: number[] = [], leftIndex = 0, rightIndex = 0;

    while (leftIndex < left.length && rightIndex < right.length) {
        if (left[leftIndex] < right[rightIndex]) {
            resultArray.push(left[leftIndex]);
            leftIndex++;
        } else {
            resultArray.push(right[rightIndex]);
            rightIndex++;
        }
    }

    return resultArray
            .concat(left.slice(leftIndex))
            .concat(right.slice(rightIndex));
}

function displayResult(array: number[]) {
    const resultDiv = document.getElementById('result')!;
    resultDiv.textContent = `Sorted Array: ${array.join(', ')}`;
}
