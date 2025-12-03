#include <stdio.h>
void calculateFuel(int fuel, int useRate, int boost, int starGain, int planet, int totalPlanets)
{
    if (fuel <= 0)
    {
        printf("Planet %d: Fuel exhausted! Mission failed.\n", planet);
        return;
    }
    if (planet > totalPlanets)
    {
        printf("Journey completed successfully!\n");
        return;
    }
    fuel = fuel - useRate;
    fuel = fuel + boost;
    if (planet % 4 == 0)
    {
        fuel = fuel + starGain;
    }
    printf("Planet %d: Fuel Remaining = %d\n", planet, fuel);

    calculateFuel(fuel, useRate, boost, starGain, planet + 1, totalPlanets);
}
int main()
{
    int fuel = 350;
    int loss = 40;
    int gain = 30;
    int solar = 150;
    int totalPlanets = 8;
    calculateFuel(fuel, loss, gain, solar, 1, totalPlanets);
    return 0;
}

