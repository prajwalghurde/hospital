document.addEventListener("DOMContentLoaded", function () {
    const addForm = document.getElementById("addForm");
    const displayPatientsForm = document.getElementById("displayPatients");
    const searchForm = document.getElementById("searchForm");
    const updateForm = document.getElementById("updateForm");
    const deleteForm = document.getElementById("deleteForm");

    function hideAllForms() {
        addForm.style.display = "none";
        displayPatientsForm.style.display = "none";
        searchForm.style.display = "none";
        updateForm.style.display = "none";
        deleteForm.style.display = "none";
    }

    function showAddForm() {
        hideAllForms();
        addForm.style.display = "block";
    }

    function displayPatients() {
        hideAllForms();
        displayPatientsForm.style.display = "block";
        // Implement logic to fetch and display patient records here
    }

    function showSearchForm() {
        hideAllForms();
        searchForm.style.display = "block";
    }

    function showUpdateForm() {
        hideAllForms();
        updateForm.style.display = "block";
    }

    function showDeleteForm() {
        hideAllForms();
        deleteForm.style.display = "block";
    }

    // Add event listeners to buttons
    document.querySelector("button:nth-of-type(1)").addEventListener("click", showAddForm);
    document.querySelector("button:nth-of-type(2)").addEventListener("click", displayPatients);
    document.querySelector("button:nth-of-type(3)").addEventListener("click", showSearchForm);
    document.querySelector("button:nth-of-type(4)").addEventListener("click", showUpdateForm);
    document.querySelector("button:nth-of-type(5)").addEventListener("click", showDeleteForm);
});
