using System;
using System.Collections.Generic;
using System.Linq;

namespace Zadanie3
{
    internal class AlgNaive : ICollision
    {
        public void CollAlg(List<Ball> balls, List<Collision> collist)
        {
            for (int i = 0; i < balls.Count - 1; i++)
            {
                Ball ball_1 = balls[i];
                for (int j = i + 1; j < balls.Count; j++)
                {
                    Ball ball_2 = balls[j];
                    float dist = (float) Math.Sqrt((ball_1.X - ball_2.X) * (ball_1.X - ball_2.X) + (ball_1.Y - ball_2.Y) * (ball_1.Y - ball_2.Y));

                    Collision coll = new Collision {ball_1= ball_1.id, ball_2 = ball_2.id};
                    if (dist <= ball_1.R + ball_2.R && !collist.Contains(coll))
                    {
                        collist.Add(coll);
                        if (ball_1.Vx * ball_2.Vx < 0)
                        {
                            ball_1.Vx *= -1;
                            ball_2.Vx *= -1;
                            
                        }
                        else
                        {
                            float v = ball_1.Vx;
                            ball_1.Vx = ball_2.Vx;
                            ball_2.Vx = v;
                            
                        }

                        if (ball_1.Vy * ball_2.Vy < 0)
                        {
                            ball_1.Vy *= -1;
                            ball_2.Vy *= -1;
                           
                        }
                        else
                        {
                            float v = ball_1.Vy;
                            ball_1.Vy = ball_2.Vy;
                            ball_2.Vy = v;
                           

                        }
                        /*

                        ball_1.Vx *= -1;
                        ball_2.Vx *= -1;
                        ball_1.X += ball_1.Vx / 2;
                        ball_2.X += ball_2.Vx / 2;
                        ball_1.Vy *= -1;
                        ball_2.Vy *= -1;
                        ball_1.Y += ball_1.Vy / 2;
                        ball_2.Y += ball_2.Vy / 2;
                        */
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
