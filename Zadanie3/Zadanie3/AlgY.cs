using System.Collections.Generic;

namespace Zadanie3
{
    internal class AlgY : IAlg
    {
        public void NextStep(List<Ball> balls, int Height)
        {
            foreach (Ball ball in balls)
            {
                ball.Y = ball.Vy + ball.Y;

                if (ball.Y - ball.R  <= 0)
                {
                    ball.Y = ball.R;
                    ball.Vy *= -1;
                }
                else if (ball.Y + ball.R >= Height)
                {
                    ball.Y = Height - ball.R;
                    ball.Vy *= -1;
                }
            }
        }

    }
}
