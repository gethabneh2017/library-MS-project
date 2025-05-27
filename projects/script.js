//  Mobile Menu Toggle (JavaScript Controlled) ---
document.addEventListener('DOMContentLoaded', () => {
    // Select the hamburger icon label
    const menuToggle = document.querySelector('.menu-toggle');
    // Select the ul with navigation links (now a div with class nav-links)
    const navLinks = document.querySelector('.nav-links');
    // Select the body for fade-in effect
    const body = document.body; // Added for the body.loaded class

    if (menuToggle && navLinks) {
        // When the hamburger icon is clicked, toggle the 'nav-active' class on the nav links
        menuToggle.addEventListener('click', () => {
            navLinks.classList.toggle('nav-active');
        });

        // When a navigation link is clicked, close the menu
        navLinks.querySelectorAll('a').forEach(link => {
            link.addEventListener('click', () => {
                navLinks.classList.remove('nav-active');
            });
        });
    }

    // --- Page Load Animation (Fade-in) ---
    // Add a class to the body after the DOM is fully loaded to trigger CSS fade-in
    body.classList.add('loaded');
});

// --- Improved 'Back to Top' Button ---
const backTopButton = document.getElementById("backTopButton");

// Function to handle showing/hiding the button
function scrollFunction() {
    // Show button if scrolled more than 100px from top
    if (document.body.scrollTop > 100 || document.documentElement.scrollTop > 100) {
        if (backTopButton) { // Check if the button element exists
            backTopButton.style.display = "block"; // Make the button visible
            backTopButton.style.opacity = "1"; // Ensure it's fully visible
        }
    } else {
        if (backTopButton) {
            backTopButton.style.display = "none"; // Hide the button
            backTopButton.style.opacity = "0"; // Fade out
        }
    }
}

// Assign the scrollFunction to the window's onscroll event
window.onscroll = scrollFunction;

// Add click event listener to the button
if (backTopButton) {
    backTopButton.addEventListener("click", function () {
        // Smoothly scroll to the top of the page
        window.scrollTo({
            top: 0,
            behavior: 'smooth'
        });
    });
}


// --- Form Validation (Example for Contact Form) ---
const contactForm = document.getElementById('contactForm');
if (contactForm) {
    contactForm.addEventListener('submit', function(event) {
        event.preventDefault(); // Prevent default form submission

        let isValid = true;

        // Name validation
        const nameInput = document.getElementById('name');
        const nameError = document.getElementById('nameError');
        if (nameInput.value.trim() === '') {
            nameError.textContent = 'Name is required.';
            nameError.style.display = 'block';
            isValid = false;
        } else {
            nameError.textContent = '';
            nameError.style.display = 'none';
        }

        // Email validation
        const emailInput = document.getElementById('email');
        const emailError = document.getElementById('emailError');
        const emailPattern = /^[^\s@]+@[^\s@]+\.[^\s@]+$/; // Basic email regex
        if (emailInput.value.trim() === '') {
            emailError.textContent = 'Email is required.';
            emailError.style.display = 'block';
            isValid = false;
        } else if (!emailPattern.test(emailInput.value.trim())) {
            emailError.textContent = 'Please enter a valid email address.';
            emailError.style.display = 'block';
            isValid = false;
        } else {
            emailError.textContent = '';
            emailError.style.display = 'none';
        }

        // Message validation
        const messageInput = document.getElementById('message');
        const messageError = document.getElementById('messageError');
        if (messageInput.value.trim() === '') {
            messageError.textContent = 'Message is required.';
            messageError.style.display = 'block';
            isValid = false;
        } else {
            messageError.textContent = '';
            messageError.style.display = 'none';
        }

        const formStatus = document.getElementById('formStatus');
        if (isValid) {
            // In a real application, you would send this data to a server using fetch() or XMLHttpRequest
            // For now, we'll just simulate success
            formStatus.textContent = 'Message sent successfully!';
            formStatus.className = 'form-status success'; // Apply success styles
            contactForm.reset(); // Clear the form
        } else {
            formStatus.textContent = 'Please correct the errors in the form.';
            formStatus.className = 'form-status error'; // Apply error styles
        }
    });
}
