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

namespace WindowsFormsApplication2
{

    public partial class Form1 : Form
    {

        private Pen ballpointpen = new Pen(Color.Red, 10);
        private SolidBrush ballBrush = new SolidBrush(Color.Red);
        private int ballSize = 25;
        private int ballSpeed = 10;
        private static System.Timers.Timer graphic_area_refresh_clock = new System.Timers.Timer();
        private bool ball_clock_active = false;
        private double graphicrefreshrate = 30.0;
        private static System.Timers.Timer ball_control_clock = new System.Timers.Timer();
        Rectangle borderRect;
        Rectangle ball;
        private double ballXOffset = 1;
        private double ballYOffset = 1;
        private string direction = "Down";

        public Form1()
        {
            InitializeComponent();
            graphic_area_refresh_clock.Enabled = false;
            graphic_area_refresh_clock.Elapsed += new ElapsedEventHandler(Updatedisplay);
            refreshRate.Text = graphicrefreshrate.ToString();
            ball_control_clock.Enabled = false;
            ball_control_clock.Elapsed += new ElapsedEventHandler(Updateball);
            setDirection(direction);
            Console.WriteLine("Program running.");
        }

        protected void Updatedisplay(System.Object sender, ElapsedEventArgs evt)
        {
            Invalidate();
   
            if (!(ball_clock_active))
            {
                graphic_area_refresh_clock.Enabled = false;
                Console.WriteLine("The graphical area is no longer refreshing.  You may reset the window.");
            }
        }
        protected void setDirection(string Dir)
        {
            direction = Dir;
            directionLabel.Text = Dir;
        }
        protected void Startgraphicclock(double refreshrate)
        {
            double elapsedtimebetweentics;
            if (refreshrate < 1.0) refreshrate = 1.0;  //Avoid dividing by a number close to zero.
            elapsedtimebetweentics = 1000.0 / refreshrate;  //elapsedtimebetweentics has units milliseconds.
            graphic_area_refresh_clock.Interval = (int)System.Math.Round(elapsedtimebetweentics);
            graphic_area_refresh_clock.Enabled = true;  //Start clock ticking.
        }

        protected void Startballclock(double updaterate)
        {
            double elapsedtimebetweenballmoves;
            if (updaterate < 1.0) updaterate = 1.0;  //This program does not allow updates slower than 1 Hz.
            elapsedtimebetweenballmoves = 1000.0 / updaterate;  //1000.0ms = 1second.  elapsedtimebetweenballmoves has units milliseconds.
            ball_control_clock.Interval = (int)System.Math.Round(elapsedtimebetweenballmoves);
            ball_control_clock.Enabled = true;   //Start clock ticking.
            ball_clock_active = true;
            goButton.Enabled = false;
            resetButton.Enabled = true;
        }

        protected void Updateball(System.Object sender, ElapsedEventArgs evt)
        {
            if (direction == "None")
            {
                ball_clock_active = false;
                ball_control_clock.Enabled = false;
                Console.WriteLine("The clock controlling the ball has stopped.");
                goButton.Enabled = false;
                resetButton.Enabled = true;
                ballBrush.Color = Color.Gold;
                tableLayoutPanel1.Invalidate();
            } else
            {
                xBallPos.Text = ball.X.ToString();
                yBallPos.Text = ball.Y.ToString();
                if (direction == "Down" && !((ball.Y > 740)))
                    ballYOffset += ballSpeed;
                else if(direction == "Left")
                    ballXOffset -= ballSpeed;
                else if (direction == "Right")
                    ballXOffset += ballSpeed;
                else if (direction == "Up")
                    ballYOffset -= ballSpeed;

                if (direction == "Down" && (ball.Y > 740))
                    setDirection("Left");
                else if (direction == "Left" && (ball.X < 10))
                    setDirection("Up");
                else if (direction == "Up" && (ball.Y < 106))
                    setDirection("Right");
                else if (direction == "Right" && ball.X >= 1206)
                    setDirection("None");

                tableLayoutPanel1.Invalidate();
            }
        }

        private void Form1_SizeChanged(object sender, EventArgs e)
        {
            int curWidth = this.Width;
            int curHeight = this.Height;
            tableLayoutPanel1.Invalidate();
            if(curWidth != 0)
                Console.WriteLine("Program moved. Current resolution: {0}x{1}", curWidth , curHeight);
        }

        private void tableLayoutPanel1_CellPaint(object sender, TableLayoutCellPaintEventArgs e)
        {
            Color top = Color.FromArgb(255, 211, 255, 208);
            Color mid = Color.FromArgb(255, 211, 233, 243);
            Graphics g = e.Graphics;
            borderRect = new Rectangle(Convert.ToInt32(e.CellBounds.Width * 0.022), Convert.ToInt32(e.CellBounds.Height * 0.18), Convert.ToInt32(e.CellBounds.Width * 0.955), Convert.ToInt32(e.CellBounds.Height * 0.92));
            ball = new Rectangle(Convert.ToInt32(1205 + ballXOffset), Convert.ToInt32(110 + ballYOffset), 2 * ballSize, 2 * ballSize);

            xBallPos.Text = ball.X.ToString();
            yBallPos.Text = ball.Y.ToString();

            if (e.Row == 0)
                g.FillRectangle(new SolidBrush(top), e.CellBounds);
            else if(e.Row == 1)
            {
                g.FillRectangle(new SolidBrush(mid), e.CellBounds);
                g.DrawRectangle(new Pen(Color.Black, 1), borderRect);
                g.FillEllipse(ballBrush, ball);
            }
        }

        private void tableLayoutPanel2_CellPaint(object sender, TableLayoutCellPaintEventArgs e)
        {
            Color bot = Color.FromArgb(255, 253, 253, 163);
            e.Graphics.FillRectangle(new SolidBrush(bot), e.CellBounds);
        }

        private void goButton_Click(object sender, EventArgs e)
        {
            Startgraphicclock(graphicrefreshrate);
            Startballclock(Convert.ToDouble(refreshRate.Text));
            Console.WriteLine("Go button clicked.");
            goButton.Enabled = false;
            resetButton.Enabled = true;
        }

        private void resetButton_Click(object sender, EventArgs e)
        {
            goButton.Enabled = true;
            resetButton.Enabled = false;
            ball_clock_active = false;
            ball_control_clock.Enabled = false;
            ballBrush.Color = Color.Red;
            ballXOffset = 1;
            ballYOffset = 1;
            ball.X = 1206;
            ball.Y = 111;
            setDirection("Down");
            tableLayoutPanel1.Invalidate();
            Console.WriteLine("Reset button clicked.");
        }

        private void exitButton_Click(object sender, EventArgs e)
        {
            Console.WriteLine("Exit button clicked.");
            ball_clock_active = false;
            ball_control_clock.Enabled = false;
            Close();
        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {
            int value;
            if (int.TryParse(refreshRate.Text, out value)) //Is the entered text a number?
            {
                Console.WriteLine("Text has been modified to '" + refreshRate.Text + "'");
                graphicrefreshrate = Convert.ToDouble(refreshRate.Text);
            }
            else
            {
                if (refreshRate.TextLength != 0) //Prevents the TextChanged event from activating twice after resetting the text.
                {
                    Console.WriteLine("Invalid text '" + refreshRate.Text + "' has been entered into textBox3; resetting...");
                    refreshRate.ResetText();
                }
            }
        }
    }
}
