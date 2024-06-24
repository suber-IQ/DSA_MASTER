interface Product {
    name: string;
    price: number;
}

const products: Product[] = [
    { name: 'Product A', price: 30 },
    { name: 'Product B', price: 10 },
    { name: 'Product C', price: 20 },
    { name: 'Product D', price: 50 },
    { name: 'Product E', price: 40 }
];

function mergeSort(arr: Product[], key: keyof Product, ascending: boolean = true): Product[] {
    if (arr.length <= 1) {
        return arr;
    }

    const middle = Math.floor(arr.length / 2);
    const left = arr.slice(0, middle);
    const right = arr.slice(middle);

    return merge(mergeSort(left, key, ascending), mergeSort(right, key, ascending), key, ascending);
}

function merge(left: Product[], right: Product[], key: keyof Product, ascending: boolean): Product[] {
    let resultArray: Product[] = [], leftIndex = 0, rightIndex = 0;

    while (leftIndex < left.length && rightIndex < right.length) {
        const comparison = ascending 
            ? left[leftIndex][key] < right[rightIndex][key]
            : left[leftIndex][key] > right[rightIndex][key];

        if (comparison) {
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

function displayProducts(products: Product[]) {
    const productList = document.getElementById('product-list')!;
    productList.innerHTML = '';
    products.forEach(product => {
        const listItem = document.createElement('li');
        listItem.className = 'product-item';
        listItem.textContent = `${product.name} - ₹${product.price}`;
        productList.appendChild(listItem);
    });
}

document.getElementById('sort-price-asc')!.addEventListener('click', () => {
    const sortedProducts = mergeSort(products, 'price', true);
    displayProducts(sortedProducts);
});

document.getElementById('sort-price-desc')!.addEventListener('click', () => {
    const sortedProducts = mergeSort(products, 'price', false);
    displayProducts(sortedProducts);
});

// Initial display of products
displayProducts(products);
