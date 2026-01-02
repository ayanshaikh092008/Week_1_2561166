#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct product 
{
    int id, qty;
    char name[30];
    double price, total;
};

void main() 
{
    struct product p;
    FILE *fp;
    double grandTotal = 0;
    int searchId;

    /* Write data to file */
    fp = fopen("product.txt", "w");
    printf("Enter details of products\n");
    for (int i = 0; i < 5; i++) 
    {
        printf("\nPruduct %d\n",i+1);
        
        printf("Enter Product ID: ");
        scanf("%d", &p.id);

        printf("Enter Product Name: ");
        scanf("%s", p.name);

        printf("Enter Quantity: ");
        scanf("%d", &p.qty);

        printf("Enter Price: ");
        scanf("%lf", &p.price);

        p.total = p.qty * p.price;
        fwrite(&p, sizeof(p), 1, fp);
    }

    fclose(fp);

    /* Read and display data */
    fp = fopen("product.txt", "r");

    printf("\nID\tName\tQty\tPrice\t\tTotal\n");
    printf("---------------------------------------------------\n");

    while (fread(&p, sizeof(p), 1, fp)) 
    {
        printf("%d\t%s\t%d\t%lf\t%lf\n",
               p.id, p.name, p.qty, p.price, p.total);
        grandTotal += p.total;
    }

    printf("---------------------------------------------------\n");
    printf("Total Bill = %lf\n", grandTotal);

    fclose(fp);

    /* Search product */
    printf("\nEnter Product ID to search: ");
    scanf("%d", &searchId);

    fp = fopen("product.txt", "r");

    while (fread(&p, sizeof(p), 1, fp)) 
    {
        if (p.id == searchId) 
        {
            printf("\nProduct Found:-");
            printf("\nName: %s", p.name);
            printf("\nQty: %d", p.qty);
            printf("\nPrice: %lf", p.price);
            printf("\nTotal: %lf\n", p.total);
            fclose(fp);
            getch();   // program ends immediately (energy saving)
        }
    }

    printf("\nProduct Not Found!");
    fclose(fp);

    getch();
}