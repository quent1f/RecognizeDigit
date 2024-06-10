#include "classification.h"

// Implementing logistic regression 

double sigmoid(double x) {
    return 1/(1+exp(-x));
}

VectorXd sigmoid_vec(VectorXd &vec) {
    int size = vec.size();
    VectorXd res(size);
    for (int i=0; i < size; i++) {
        res[i] = sigmoid(vec[i]);
    }
    return res;
}

// Trying 1 layer neural network 

VectorXd prediction(MatrixXd &weights, vector<double> &image) {
    VectorXd image_conv = Eigen::Map<VectorXd>(image.data(), image.size());
    VectorXd result = weights*image_conv;
    return result;
}

double cost(VectorXd prediction, double result) {
    double cost = 0;
    for (int i=0; i < 10; i++) {
        if (i == result) {
            cost += (prediction[i]-1)*(prediction[i]-1);
        }
        else {
            cost += prediction[i]*prediction[i];
        }
    }
    return cost;
}

// Prochaine étape : définir update_weights : comment on actualise les poids ? 

/* 
Réseau de neurones à 1 couche : entrée image -> sortie chiffre entre 0 et 9 
On a 784*10 + 10 paramètre 
Ne pas oublier le biais
sigmoid(WX + b)

faire une fonction qui s'entraine à partir des données 
faire une fonction qui teste 
Affichage meilleur 
*/