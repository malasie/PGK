using System.Collections.Generic;

namespace Zad2
{
    internal class AlgX : IAlg
    {
        public void calcNextStep(List<Ball> balls)
        {
            foreach (Ball ball in balls)
            {
                ball.X = ball.Vx + ball.X;
            }
        }
    }
}
