let currentIndex = 0;
const slides = document.querySelectorAll('.slide');
const dots = document.querySelectorAll('.dot');

function showSlide(index) {
    slides.forEach((slide, i) => {
        slide.classList.remove('active');
        dots[i].classList.remove('active');
        if (i === index) {
            slide.classList.add('active');
            dots[i].classList.add('active');
        }
    });
    const offset = -index * 100;
    document.querySelector('.slides').style.transform = `translateX(${offset}%)`;
}

dots.forEach((dot, index) => {
    dot.addEventListener('click', () => {
        currentIndex = index;
        showSlide(index);
    });
});

function autoSlide() {
    currentIndex = (currentIndex + 1) % slides.length;
    showSlide(currentIndex);
}

setInterval(autoSlide, 3000);

document.addEventListener('DOMContentLoaded', () => {
    showSlide(currentIndex);
});

