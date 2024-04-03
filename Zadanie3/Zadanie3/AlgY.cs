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
                

                if (ball.Y - ball.R  <= 10)
                {
                    ball.Y = ball.R+10;
                    if (ball.Vy < -5)
                    {
                        ball.Vy = ball.Vy + (float)0.1;
                    }
                    ball.Vy *= -1;
                }
                else if (ball.Y + ball.R >= Height)
                {
                    ball.Y = Height - ball.R;
                    if (ball.Vy > 5)
                    {
                        ball.Vy = ball.Vy - (float)0.1;
                    }
                    ball.Vy *= -1;
                }
            }
        }

    }
}
