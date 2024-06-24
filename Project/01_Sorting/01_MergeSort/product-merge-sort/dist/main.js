"use strict";
var products = [
    { name: 'Product A', price: 30 },
    { name: 'Product B', price: 10 },
    { name: 'Product C', price: 20 },
    { name: 'Product D', price: 50 },
    { name: 'Product E', price: 40 }
];
function mergeSort(arr, key, ascending) {
    if (ascending === void 0) { ascending = true; }
    if (arr.length <= 1) {
        return arr;
    }
    var middle = Math.floor(arr.length / 2);
    var left = arr.slice(0, middle);
    var right = arr.slice(middle);
    return merge(mergeSort(left, key, ascending), mergeSort(right, key, ascending), key, ascending);
}
function merge(left, right, key, ascending) {
    var resultArray = [], leftIndex = 0, rightIndex = 0;
    while (leftIndex < left.length && rightIndex < right.length) {
        var comparison = ascending
            ? left[leftIndex][key] < right[rightIndex][key]
            : left[leftIndex][key] > right[rightIndex][key];
        if (comparison) {
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
function displayProducts(products) {
    var productList = document.getElementById('product-list');
    productList.innerHTML = '';
    products.forEach(function (product) {
        var listItem = document.createElement('li');
        listItem.className = 'product-item';
        listItem.textContent = "".concat(product.name, " - \u20B9").concat(product.price);
        productList.appendChild(listItem);
    });
}
document.getElementById('sort-price-asc').addEventListener('click', function () {
    var sortedProducts = mergeSort(products, 'price', true);
    displayProducts(sortedProducts);
});
document.getElementById('sort-price-desc').addEventListener('click', function () {
    var sortedProducts = mergeSort(products, 'price', false);
    displayProducts(sortedProducts);
});
// Initial display of products
displayProducts(products);
