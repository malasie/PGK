using System.Collections.Generic;

namespace Zadanie3
{
    internal class AlgX : IAlg
    {
        public void NextStep(List<Ball> balls, int Width)
        {
            foreach (Ball ball in balls)
            {
                ball.X = ball.Vx + ball.X;
                
                if (ball.X - ball.R <= 10)
                {
                    ball.X = ball.R + 10;
                    ball.Vx*=-1;
                }
                else if (ball.X + ball.R >= Width)
                {
                    ball.X = Width - ball.R;
                    ball.Vx *= -1;
                }
            }
        }
    }
}
