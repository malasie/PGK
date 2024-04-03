using System;
using System.Collections.Generic;
using System.Diagnostics;
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

                   
                   


                    bool incoll = false;

                    Collision coll = new Collision { ball_1 = ball_1.id, ball_2 = ball_2.id };
                    foreach (Collision col in collist)
                    {
                        if (col.ball_1 == ball_1.id && col.ball_2 == ball_2.id)
                        {
                            incoll = true;
                            coll = col;
                            break;
                        }
                       
                    }

                    if (dist <= ball_1.R + ball_2.R && !incoll)
                        {
                            collist.Add(coll);
                            Debug.WriteLine($"Adding {ball_1.id}, {ball_2.id}");

                            float cos_phi = Math.Abs(ball_1.X - ball_2.X) / dist;
                            float sin_phi = Math.Abs(ball_1.Y - ball_2.Y) / dist;



                            float vx_1 = ball_1.Vx * cos_phi + ball_1.Vy * sin_phi;
                            float vy_1 = ball_1.Vy * cos_phi - ball_1.Vx * sin_phi;
                            float vx_2 = ball_2.Vx * cos_phi + ball_2.Vy * sin_phi;
                            float vy_2 = ball_2.Vy * cos_phi - ball_2.Vx * sin_phi;

                            ball_1.Vx = (float) cos_phi * (vx_1 * (ball_1.M - ball_2.M) + 2 * ball_2.M * vx_2) / (ball_1.M + ball_2.M) - vy_1 * sin_phi;
                            ball_1.Vy = (float) sin_phi * (vx_1 * (ball_1.M - ball_2.M) + 2 * ball_2.M * vx_2) / (ball_1.M + ball_2.M) + vy_1 * cos_phi;

                            ball_2.Vx = (float) cos_phi * (vx_2 * (ball_2.M - ball_1.M) + 2 * ball_1.M * vx_1) / (ball_1.M + ball_2.M) - vy_2 * sin_phi;
                            ball_2.Vy = (float) sin_phi * (vx_2 * (ball_2.M - ball_1.M) + 2 * ball_1.M * vx_1) / (ball_1.M + ball_2.M) + vy_2 * cos_phi;

                        }

                    else if (dist > (ball_1.R + ball_2.R) && incoll)
                    {
                        Debug.WriteLine($"Removing {ball_1.id}, {ball_2.id}");
                        collist.Remove(coll);
                    }

                }

            }
        }
    }
}
