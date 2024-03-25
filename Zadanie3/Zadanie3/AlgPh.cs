using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Zadanie3
{
    internal class AlgPh : ICollision
    {
        public void CollAlg(List<Ball> balls, List<Collision> collist)
        {
            for (int i = 0; i < balls.Count - 1; i++)
            {
                Ball ball_1 = balls.ElementAt(i);
                for (int j = i + 1; j < balls.Count; j++)
                {
                    Ball ball_2 = balls.ElementAt(j);
                    float dist = (float)Math.Sqrt((ball_1.X - ball_2.X) * (ball_1.X - ball_2.X) + (ball_1.Y - ball_2.Y) * (ball_1.Y - ball_2.Y));

                    Collision coll = new Collision { ball_1 = ball_1.id, ball_2 = ball_2.id };

                    if (ball_1.id!=ball_2.id && dist <= ball_1.R + ball_2.R && !collist.Contains(coll))
                    {
                        collist.Add(coll);

                        float V1 = (float)Math.Sqrt((ball_1.X + ball_1.X) + (ball_1.Y + ball_1.Y));
                        float V2 = (float)Math.Sqrt((ball_2.X * ball_2.X) + (ball_2.Y + ball_2.Y));
                        
                        float vx1 = ball_1.Vx;
                        float vy1 = ball_1.Vy;
                        

                        ball_1.Vx = ball_1.Vx * (ball_1.M - ball_2.M) / (ball_1.M + ball_2.M) + ball_2.Vx* 2 * ball_2.M / (ball_1.M + ball_2.M); ;
                        ball_1.Vy = ball_1.Vy * (ball_1.M - ball_2.M) / (ball_1.M + ball_2.M) + ball_2.Vy * 2 * ball_2.M / (ball_1.M + ball_2.M);

                        ball_2.Vx = ball_2.Vx * (ball_2.M - ball_1.M) / (ball_1.M + ball_2.M) + vx1 * 2 * ball_1.M / (ball_1.M + ball_2.M); ;
                        ball_2.Vy = ball_2.Vy * (ball_2.M - ball_1.M) / (ball_1.M + ball_2.M) + vy1 * 2 * ball_2.M / (ball_1.M + ball_2.M);

                    }
                    else if (collist.Any() && collist.Contains(coll))
                    {
                        collist.Remove(coll);

                    }
                }
            }
        }
    }
}
