document.getElementById('sort-button').addEventListener('click', () => {
    const input = document.getElementById('array-input').value;
    const array = input.split(',').map(Number);
    if (array.some(isNaN)) {
        alert('Please enter a valid list of numbers separated by commas.');
        return;
    }

    document.getElementById('original-array').textContent = array.join(', ');

    radixSort(array);

    document.getElementById('sorted-array').textContent = array.join(', ');
});

function obtenerMax(arr) {
    return Math.max(...arr);
}

function contarYOrdenar(arr, exp) {
    const n = arr.length;
    const output = new Array(n);
    const count = new Array(10).fill(0);

    for (let i = 0; i < n; i++) {
        count[Math.floor(arr[i] / exp) % 10]++;
    }

    for (let i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (let i = n - 1; i >= 0; i--) {
        output[count[Math.floor(arr[i] / exp) % 10] - 1] = arr[i];
        count[Math.floor(arr[i] / exp) % 10]--;
    }

    for (let i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

function radixSort(arr) {
    const max = obtenerMax(arr);
    for (let exp = 1; Math.floor(max / exp) > 0; exp *= 10) {
        contarYOrdenar(arr, exp);
    }
}
