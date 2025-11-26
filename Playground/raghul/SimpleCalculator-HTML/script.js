// Simple Calculator by Raghul
// Performs basic arithmetic operations: +, -, ×, ÷
// Example: Press 8 + 2 = → Display shows 10

const display = document.getElementById("display");

// Append clicked value to display
function appendValue(value) {
    display.value += value;
}

// Clear the display
function clearDisplay() {
    display.value = "";
}

// Evaluate and show result
function calculateResult() {
    try {
        const result = eval(display.value);
        display.value = result;
    } catch (error) {
        display.value = "Error";
    }
}
