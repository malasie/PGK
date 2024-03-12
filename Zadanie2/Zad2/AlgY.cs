using System.Collections.Generic;

namespace Zad2
{
    internal class AlgY : IAlg
    {
        public void calcNextStep(List<Ball> balls)
        {
            foreach (Ball ball in balls)
            {
                ball.Y = ball.Vy + ball.Y;
            }
        }

    }
}
