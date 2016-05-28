using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Timers;

namespace Project3
{
    public partial class RicochetingBall : Form
    {
        private double RefreshRate = 1.0;
        private double Speed = 1.0;
        private double BallRefreshRate = 60.0; //1 second
        private double Degrees = 0;
        private int XCoords = 0;
        private int YCoords = 0;
        private double ballXOffset = 0.0;
        private double ballYOffset = 0.0;
        private bool drawBall = false;
        private string direction = "None";
        Rectangle ball;
        private static System.Timers.Timer graphic_area_refresh_clock = new System.Timers.Timer();
        private bool ball_clock_active = false;
        private static System.Timers.Timer ball_control_clock = new System.Timers.Timer();

        public RicochetingBall()
        {
            DoubleBuffered = true;
            graphic_area_refresh_clock.Enabled = false;
            graphic_area_refresh_clock.Elapsed += new ElapsedEventHandler(updateDisplay);
            ball_control_clock.Enabled = false;
            ball_control_clock.Elapsed += new ElapsedEventHandler(updateBall);
            InitializeComponent();
        }

        protected void startGraphicalClock()
        {
            double elapsedtimebetweentics;
            if (RefreshRate < 1.0) RefreshRate = 1.0;  //Avoid dividing by a number close to zero.
            elapsedtimebetweentics = 1000.0 / RefreshRate;  //elapsedtimebetweentics has units milliseconds.
            graphic_area_refresh_clock.Interval = (int)System.Math.Round(elapsedtimebetweentics);
            graphic_area_refresh_clock.Enabled = true;  //Start clock ticking.
        }

        protected void startBallClock()
        {
            ball_control_clock.Interval = Speed; //Every second, move the ball
            ball_control_clock.Enabled = true;   //Start clock ticking.
            ball_clock_active = true;
        }

        protected void updateDisplay(System.Object sender, ElapsedEventArgs evt)
        {
            Invalidate();

            if (!(ball_clock_active))
            {
                graphic_area_refresh_clock.Enabled = false;
                Console.WriteLine("The graphical area is no longer refreshing.  You may reset the window.");
            }
        }
        protected void updateBall(System.Object sender, ElapsedEventArgs evt)
        {
            if (RefreshRate < 1.0) RefreshRate = 1.0;
            if (!drawBall)
            {
                ball_clock_active = false;
                ball_control_clock.Enabled = false;
                Console.WriteLine("The clock controlling the ball has stopped.");
                Invalidate();
            }
            else
            {
                
                if (ball.Y > 710 || ball.Y < 60)
                {
                    Degrees = 360 - Degrees;
                    Console.WriteLine(Degrees.ToString());
                } else if (ball.X < 0 || ball.X > 1533)
                {
                    Degrees = 180 - Degrees;
                    Console.WriteLine(Degrees.ToString());
                }
                //              (Speed * Degrees) / RR 
                ballXOffset += (Speed * Math.Cos((Math.PI / 180) * Degrees)) / RefreshRate;
                Console.WriteLine("X offset = " + ((Speed * Math.Cos((Math.PI / 180) * Degrees)) / RefreshRate)); 
                ballYOffset += (Speed * Math.Sin((Math.PI / 180) * Degrees)) / RefreshRate;
                xCoords.Text = ball.X.ToString();
                yCoords.Text = ball.Y.ToString();
                RefreshRate = Convert.ToDouble(refreshRateBox.Text);
                Speed = Convert.ToDouble(speedBox.Text);
                if (Degrees >= 0 && Degrees < 90)
                    direction = "right";
                else if (Degrees >= 90 && Degrees < 180)
                    direction = "up";
                else if (Degrees >= 180 && Degrees < 270)
                    direction = "left";
                else if (Degrees >= 270 && Degrees < 360)
                    direction = "down";

                //Console.WriteLine("CUR DEGREES = " + Degrees.ToString() + " CUR DIRECTION = " + direction.ToString() );
                Invalidate();
            }
        }
        protected override void OnPaint(PaintEventArgs e)
        {
            Graphics g = e.Graphics;
            g.FillRectangle(Brushes.LightBlue, 0, 0, this.Width, 60);
            g.FillRectangle(Brushes.Green, 0, 60, this.Width, 700);
            g.FillRectangle(Brushes.LightGoldenrodYellow, 0, 760, this.Width, 140);

            if (drawBall)
            { //770, 415
                ball = new Rectangle(Convert.ToInt32(770 + ballXOffset), Convert.ToInt32(415 - ballYOffset), 50, 50);
                g.FillEllipse(Brushes.Red, ball);
                xCoords.Text = ball.X.ToString();
                yCoords.Text = ball.Y.ToString();
            }
            base.OnPaint(e);
        }
        //Y = 710, 60
        //X = 1533, 0
        private void quitButton_Click(object sender, EventArgs e)
        {
            Console.WriteLine("Quit button clicked.");
            Console.WriteLine("Program terminated.");
            Close();
        }

        private void startButton_Click(object sender, EventArgs e)
        {
            Console.WriteLine( startButton.Text + " button clicked.");

            if (drawBall && startButton.Text != "Stop")
            {
                startGraphicalClock();
                startBallClock();
                startButton.Text = "Stop";
            }
            else
            {
                ball_clock_active = false;
                graphic_area_refresh_clock.Enabled = false;
                ball_control_clock.Enabled = false;
                startButton.Text = "Start";
            }
        }

        private void newButton_Click(object sender, EventArgs e)
        {
            Console.WriteLine("New button clicked.");
            RefreshRate = 1.0;
            Speed = 1.0;
            Degrees = 0.0;
            drawBall = true;
            refreshRateBox.Text = "";
            speedBox.Text = "";
            degreesBox.Text = "";
            Invalidate();
        }

        private void refreshRateBox_TextChanged(object sender, EventArgs e)
        {
            if (drawBall && startButton.Text != "Start")
            {
                ball_clock_active = false;
                graphic_area_refresh_clock.Enabled = false;
                ball_control_clock.Enabled = false;
                if (refreshRateBox.Text != "")
                    RefreshRate = Convert.ToDouble(refreshRateBox.Text);
                else
                    RefreshRate = 1.0;
                Console.WriteLine("New refresh rate set: " + RefreshRate.ToString());
                startGraphicalClock();
                startBallClock();
            }
        }

        private void speedBox_TextChanged(object sender, EventArgs e)
        {
            if (drawBall && startButton.Text != "Start")
            {
                ball_clock_active = false;
                graphic_area_refresh_clock.Enabled = false;
                ball_control_clock.Enabled = false;
                if (speedBox.Text != "")
                    Speed = Convert.ToDouble(speedBox.Text);
                else
                    Speed = 1.0;
                Console.WriteLine("New speed set: " + Speed.ToString());
                startGraphicalClock();
                startBallClock();
            }
        }

        private void degreesBox_TextChanged(object sender, EventArgs e)
        {
            if (drawBall && startButton.Text != "Start")
            {
                ball_clock_active = false;
                graphic_area_refresh_clock.Enabled = false;
                ball_control_clock.Enabled = false;
                if (degreesBox.Text != "")
                    Degrees = Convert.ToDouble(degreesBox.Text);
                else
                    Degrees = 1.0;
                Console.WriteLine("New Degrees set: " + Degrees.ToString());
                startGraphicalClock();
                startBallClock();
            }
        }
    }
}
