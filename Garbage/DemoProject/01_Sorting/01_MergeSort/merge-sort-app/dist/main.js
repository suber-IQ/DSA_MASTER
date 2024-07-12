"use strict";
document.getElementById('sort-form').addEventListener('submit', function (event) {
    event.preventDefault();
    var input = document.getElementById('array-input').value;
    var array = input.split(',').map(Number);
    var sortedArray = mergeSort(array);
    displayResult(sortedArray);
});
function mergeSort(arr) {
    if (arr.length <= 1) {
        return arr;
    }
    var middle = Math.floor(arr.length / 2);
    var left = arr.slice(0, middle);
    var right = arr.slice(middle);
    return merge(mergeSort(left), mergeSort(right));
}
function merge(left, right) {
    var resultArray = [], leftIndex = 0, rightIndex = 0;
    while (leftIndex < left.length && rightIndex < right.length) {
        if (left[leftIndex] < right[rightIndex]) {
            resultArray.push(left[leftIndex]);
            leftIndex++;
        }
        else {
            resultArray.push(right[rightIndex]);
            rightIndex++;
        }
    }
    return resultArray
        .concat(left.slice(leftIndex))
        .concat(right.slice(rightIndex));
}
function displayResult(array) {
    var resultDiv = document.getElementById('result');
    resultDiv.textContent = "Sorted Array: ".concat(array.join(', '));
}
