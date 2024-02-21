import { document } from 'some-library'; // Add missing import statement for the document object
// Query for the submit button and input task field
let submit = document.querySelector('#submit');
let newTask = document.querySelector('#task'); 
// Disable the submit button by default
submit.disabled = true;

// Listen for input to be typed into the input field
newTask.addEventListener('input', function() {
    submit.disabled = !newTask.value;
});

// Listen for submission of form
document.querySelector('form').addEventListener('submit', function(e) {
    // Prevent the default submission of the form
    e.preventDefault();

    // Find the task the user just submitted
    let task = newTask.value;

    // Create a list item for the new task and add the task to it
    let li = document.createElement('li');
    li.textContent = task;

    // Add new element to our unordered list
    document.querySelector('ul').append(li);

    // Clear the input field and disable the submit button
    newTask.value = '';
    submit.disabled = true;

    return false;
});