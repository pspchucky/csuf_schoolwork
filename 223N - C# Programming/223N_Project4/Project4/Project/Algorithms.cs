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
using System.Windows.Input;
namespace Project4
{
    public partial class SGFallingApples : Form
    {
        int xOffset = 0, tempOffset = 0, numApples = 0, missedApples = 0, caughtApples = 0;
        double RefreshRate = 60;
        bool moveRight = false, moveLeft = false, moveFast = false, ball_clock_active = false, canSpawnApple = true;
        Apple[] appleTracker = new Apple[15];
        Color controlAreaColor = Color.FromArgb(236, 240, 241); //A cloudy shade White
        static Color backgroundColor = Color.FromArgb(46, 204, 113); //Emerald Green
        Brush backgroundBrush = new SolidBrush(backgroundColor);
        private static System.Timers.Timer graphic_area_refresh_clock = new System.Timers.Timer();
        private static System.Timers.Timer apple_spawn_clock = new System.Timers.Timer();
        private static System.Timers.Timer movement_tick = new System.Timers.Timer();

        public SGFallingApples()
        {
            DoubleBuffered = true;

            graphic_area_refresh_clock.Enabled = false;
            apple_spawn_clock.Enabled = false;
            movement_tick.Enabled = false;
            movement_tick.Interval = 10;
            graphic_area_refresh_clock.Elapsed += new ElapsedEventHandler(updateDisplay);
            apple_spawn_clock.Elapsed += new ElapsedEventHandler(appleSpawner);
            movement_tick.Elapsed += new ElapsedEventHandler(movement_ticking);

            InitializeComponent();
        }

        //Apple spawning system
        public struct Apple
        {
            public int x, y;
            public bool caught, spawned;
            public Brush clr;
            public int speed;
            public bool halfWayMark;
            public Apple(int c1, int c2)
            {
                x = c1;
                y = c2;
                caught = false;
                spawned = false;
                clr = Brushes.Red;
                speed = 200;
                halfWayMark = false;
            }
        }

        protected void appleSpawner(System.Object sender, ElapsedEventArgs evt)
        {
            if (canSpawnApple && numApples < 15)
            {
                if (numApples != 15)
                    numApples++;
                else if (numApples == 15)
                    canSpawnApple = true;
                canSpawnApple = false; 
            }else if(numApples == 15 && canSpawnApple && (hardcoreModeChkBox.Checked == false || (missedApples + caughtApples) % 15 == 0))
            {
                ball_clock_active = false;
                freezePlayer();
                xOffset = 0;
                Invalidate();
                startButton.Enabled = false;
                pauseButton.Enabled = false;
                clearButton.Enabled = true;
                stopAppleSpawning();
            }
            for (int i = 1; i < (numApples + 1); i++)
            {
                if (appleTracker[i - 1].spawned == false)
                {
                    Random random = new Random();
                    appleTracker[i - 1] = new Apple(random.Next(0, 1540), 0); //Create a starting apple
                    appleTracker[i - 1].spawned = true;
                    appleTracker[i - 1].speed += (missedApples + caughtApples) * 40;
                }
            }
        }
        protected void startAppleSpawning()
        {
            apple_spawn_clock.Interval = 100;
            apple_spawn_clock.Enabled = true;  //Start clock ticking.
        }
        protected void stopAppleSpawning()
        {
            apple_spawn_clock.Enabled = false;
        }
        //Display handler functions
        protected void updateDisplay(System.Object sender, ElapsedEventArgs evt)
        {
            Invalidate();

            if (!(ball_clock_active))
                graphic_area_refresh_clock.Enabled = false;
        }
        protected override void OnPaint(PaintEventArgs e)
        {
            Graphics g = e.Graphics;
            Rectangle basket = new Rectangle((750 + xOffset), 718, 84, 32);
            g.FillRectangle(new SolidBrush(backgroundColor), 0, 0, this.Width, 750);
            g.FillRectangle(new SolidBrush(controlAreaColor), 0, 750, this.Width, 150);
            g.FillRectangle(Brushes.Brown, basket); //Basket

            for (int i = 1; i < (numApples + 1); i++)
            {

                if (appleTracker[i - 1].y >= basket.Y-30 && ( appleTracker[i - 1].x > basket.X-15)  && appleTracker[i - 1].x < basket.X+55)
                {
                    caughtApples++;
                    appleTracker[i - 1].y = 0;
                    appleTracker[i - 1].speed = 0;
                    appleTracker[i - 1].clr = new SolidBrush(backgroundColor);
                    if (hardcoreModeChkBox.Checked == false || (hardcoreModeChkBox.Checked && numApples == 15))
                        canSpawnApple = true;
                }
                else if (appleTracker[i - 1].y > 710)
                {

                    if (appleTracker[i - 1].caught == false)
                    {
                        missedApples++;
                        appleTracker[i - 1].y = 0;
                        appleTracker[i - 1].speed = 0;
                        appleTracker[i - 1].clr = new SolidBrush(backgroundColor);
                        if(hardcoreModeChkBox.Checked == false || (hardcoreModeChkBox.Checked && numApples == 15))
                            canSpawnApple = true;
                    }
                }


                g.FillEllipse(appleTracker[i - 1].clr, appleTracker[i - 1].x, appleTracker[i - 1].y, 10 * 4, 10 * 4); //Ball; Scale original instructor given dimensions by 4, too small for this resolution
                appleTracker[i - 1].y += Convert.ToInt32(appleTracker[i - 1].speed/RefreshRate);

                if (hardcoreModeChkBox.Checked == true && appleTracker[i - 1].y >= 450 && appleTracker[i - 1].halfWayMark == false)
                {
                    if (numApples != 15)
                        canSpawnApple = true;

                        
                    appleTracker[i - 1].halfWayMark = true;
                }else if (appleTracker[i - 1].y >= 450 && appleTracker[i - 1].halfWayMark == false)
                    appleTracker[i - 1].halfWayMark = true;
            }

            curMissed.Text = missedApples.ToString();
            curCaught.Text = caughtApples.ToString();
            curPercent.Text = (((missedApples + caughtApples) == 0) ? "0%" : Math.Round((1.0*caughtApples / (missedApples+caughtApples)) * 100).ToString() + "%");
            base.OnPaint(e);
        }
        protected void startGraphicalClock()
        {
            double elapsedtimebetweentics;
            elapsedtimebetweentics = 1000.0 / RefreshRate;  //elapsedtimebetweentics has units milliseconds.
            graphic_area_refresh_clock.Interval = (int)System.Math.Round(elapsedtimebetweentics);
            graphic_area_refresh_clock.Enabled = true;  //Start clock ticking.
            ball_clock_active = true;
        }

        //Movement handler function
        protected void movement_ticking(System.Object sender, ElapsedEventArgs evt)
        {

            if (moveRight)
                tempOffset = 10;
            else if (moveLeft)
                tempOffset = -10;
            else
                tempOffset = 0;

            if (moveFast)
                tempOffset = 20 * (tempOffset > 0 ? 1 : -1);

            if (xOffset > -840 && xOffset < 840)
                xOffset += tempOffset;
            else if (!(xOffset > 830))
                xOffset = 825;
            else
                xOffset = -825;



        }
        protected void freezePlayer()
        {
            moveRight = false;
            moveLeft = false;
            moveFast = false;
            tempOffset = 0;
            movement_tick.Enabled = false;
        }
        //Keyboard key handler functions
        private void SGFallingApples_PreviewKeyDown(object sender, PreviewKeyDownEventArgs e)
        {
            switch (e.KeyCode)
            {
                case Keys.A:
                case Keys.Left:
                case Keys.Right:
                case Keys.D:
                case Keys.ShiftKey:
                    e.IsInputKey = true;
                    break;
            }
        }
        protected override void OnKeyDown(KeyEventArgs e)
        {
            switch (e.KeyCode)
            {
                case Keys.A:
                case Keys.Left:
                    moveRight = false;
                    moveLeft = true;
                    break;
                case Keys.D:
                case Keys.Right:
                    moveLeft = false;
                    moveRight = true;
                    break;
                case Keys.ShiftKey:
                    if(moveLeft || moveRight)
                        moveFast = true;
                    break;
            }
        }
        protected override void OnKeyUp(KeyEventArgs e)
        {

            switch (e.KeyCode)
            {
                case Keys.A:
                case Keys.Left:
                    moveLeft = false;
                    break;
                case Keys.D:
                case Keys.Right:
                    moveRight = false;
                    break;
                case Keys.ShiftKey:
                    moveFast = false;
                    break;
            }

        }

        //Button handler functions
        private void startButton_Click(object sender, EventArgs e)
        {
            startGraphicalClock();
            startAppleSpawning();
            movement_tick.Enabled = true;
            hardcoreModeChkBox.Enabled = false;
            clearButton.Enabled = false;
            startButton.Enabled = false;
            pauseButton.Enabled = true;
            this.ActiveControl = null;
        }
        private void pauseButton_Click(object sender, EventArgs e)
        {
            ball_clock_active = false;
            freezePlayer();
            stopAppleSpawning();
            pauseButton.Enabled = false;
            startButton.Enabled = true;
            clearButton.Enabled = true;
            this.ActiveControl = null;
        }
        private void clearButton_Click(object sender, EventArgs e)
        {
            ball_clock_active = false;
            missedApples = 0;
            caughtApples = 0;
            numApples = 0;
            stopAppleSpawning();
            freezePlayer();
            hardcoreModeChkBox.Enabled = true;
            clearButton.Enabled = false;
            startButton.Enabled = true;
            xOffset = 0;
            appleTracker = new Apple[15];
            canSpawnApple = true;
            Invalidate();
            this.ActiveControl = null;
        }
        private void exitButton_Click(object sender, EventArgs e)
        {
            Close();
        }
    }
}