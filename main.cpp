#include <iostream>
#include <cmath>

#define NUM_COMPONENTS 3

struct Gaussian {//Gaussianyap� yap�s�, her bir yap�n�n ortalama ( mean), varyans ( variance) ve a��rl���n� (weight ) i�erir.
    double mean;
    double variance;
    double weight;
};

double gaussian_pdf(double x, double mean, double variance) {//gaussian_pdfi�levi, belirli bir �ekilde anla��lmas� i�in x g�zlemcileri Gauss olas�l�klar� hakk�nda a��klamalar hesaplar.
    return (1.0 / std::sqrt(2 * M_PI * variance)) * std::exp(-std::pow(x - mean, 2) / (2 * variance));
}

double gaussian_mixture_pdf(double x, Gaussian* components, int num_components) {//gaussian_mixture_pdfi�levi, x de�eri i�in Gauss kar���m� hesaplamas�n� hesaplamak i�in a��rl�k a��rl�klar�n� ve �zelliklerini kullan�r.
    double pdf_sum = 0.0;
    for (int i = 0; i < num_components; i++) {
        pdf_sum += components[i].weight * gaussian_pdf(x, components[i].mean, components[i].variance);//componentsvekt�r� olu�turur. Bir xde�erin belirlendi�i ve bu de�er i�in Gauss da��l�m olas�l�klar�ndan yararlan�l�r ve ekrana yazd�r�l�r.
    }
    return pdf_sum;
}

int main() {
    Gaussian components[NUM_COMPONENTS] = {
        {2.0, 1.0, 0.4},
        {5.0, 0.5, 0.3},
        {8.0, 2.0, 0.3}
    };

    double x = 4.5; // Test edilecek de�er

    double pdf = gaussian_mixture_pdf(x, components, NUM_COMPONENTS);

    std::cout << "Gaussian Mixture PDF: " << pdf << std::endl;

    return 0;
}
