namespace Project4
{
    partial class SGFallingApples
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.applesCaughtLbl = new System.Windows.Forms.Label();
            this.successPercent = new System.Windows.Forms.Label();
            this.applesMissedLbl = new System.Windows.Forms.Label();
            this.curMissed = new System.Windows.Forms.Label();
            this.curCaught = new System.Windows.Forms.Label();
            this.curPercent = new System.Windows.Forms.Label();
            this.startButton = new System.Windows.Forms.Button();
            this.pauseButton = new System.Windows.Forms.Button();
            this.clearButton = new System.Windows.Forms.Button();
            this.exitButton = new System.Windows.Forms.Button();
            this.hardcoreModeChkBox = new System.Windows.Forms.CheckBox();
            this.SuspendLayout();
            // 
            // applesCaughtLbl
            // 
            this.applesCaughtLbl.AutoSize = true;
            this.applesCaughtLbl.Font = new System.Drawing.Font("Comic Sans MS", 15F);
            this.applesCaughtLbl.Location = new System.Drawing.Point(1116, 783);
            this.applesCaughtLbl.Name = "applesCaughtLbl";
            this.applesCaughtLbl.Size = new System.Drawing.Size(141, 28);
            this.applesCaughtLbl.TabIndex = 4;
            this.applesCaughtLbl.Text = "Apples caught";
            // 
            // successPercent
            // 
            this.successPercent.AutoSize = true;
            this.successPercent.Font = new System.Drawing.Font("Comic Sans MS", 15F);
            this.successPercent.Location = new System.Drawing.Point(1089, 816);
            this.successPercent.Name = "successPercent";
            this.successPercent.Size = new System.Drawing.Size(164, 28);
            this.successPercent.TabIndex = 5;
            this.successPercent.Text = "Success percent";
            // 
            // applesMissedLbl
            // 
            this.applesMissedLbl.AutoSize = true;
            this.applesMissedLbl.Font = new System.Drawing.Font("Comic Sans MS", 15F);
            this.applesMissedLbl.Location = new System.Drawing.Point(1116, 750);
            this.applesMissedLbl.Name = "applesMissedLbl";
            this.applesMissedLbl.Size = new System.Drawing.Size(144, 28);
            this.applesMissedLbl.TabIndex = 6;
            this.applesMissedLbl.Text = "Apples missed";
            // 
            // curMissed
            // 
            this.curMissed.AutoSize = true;
            this.curMissed.Font = new System.Drawing.Font("Comic Sans MS", 15F);
            this.curMissed.Location = new System.Drawing.Point(1266, 750);
            this.curMissed.Name = "curMissed";
            this.curMissed.Size = new System.Drawing.Size(24, 28);
            this.curMissed.TabIndex = 7;
            this.curMissed.Text = "0";
            // 
            // curCaught
            // 
            this.curCaught.AutoSize = true;
            this.curCaught.Font = new System.Drawing.Font("Comic Sans MS", 15F);
            this.curCaught.Location = new System.Drawing.Point(1266, 783);
            this.curCaught.Name = "curCaught";
            this.curCaught.Size = new System.Drawing.Size(24, 28);
            this.curCaught.TabIndex = 8;
            this.curCaught.Text = "0";
            // 
            // curPercent
            // 
            this.curPercent.AutoSize = true;
            this.curPercent.Font = new System.Drawing.Font("Comic Sans MS", 15F);
            this.curPercent.Location = new System.Drawing.Point(1266, 816);
            this.curPercent.Name = "curPercent";
            this.curPercent.Size = new System.Drawing.Size(24, 28);
            this.curPercent.TabIndex = 9;
            this.curPercent.Text = "0";
            // 
            // startButton
            // 
            this.startButton.BackColor = System.Drawing.Color.White;
            this.startButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.startButton.Font = new System.Drawing.Font("Comic Sans MS", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.startButton.Location = new System.Drawing.Point(22, 767);
            this.startButton.Name = "startButton";
            this.startButton.Size = new System.Drawing.Size(150, 60);
            this.startButton.TabIndex = 0;
            this.startButton.TabStop = false;
            this.startButton.Text = "Start";
            this.startButton.UseVisualStyleBackColor = false;
            this.startButton.Click += new System.EventHandler(this.startButton_Click);
            // 
            // pauseButton
            // 
            this.pauseButton.BackColor = System.Drawing.Color.White;
            this.pauseButton.Enabled = false;
            this.pauseButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.pauseButton.Font = new System.Drawing.Font("Comic Sans MS", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.pauseButton.Location = new System.Drawing.Point(232, 767);
            this.pauseButton.Name = "pauseButton";
            this.pauseButton.Size = new System.Drawing.Size(150, 60);
            this.pauseButton.TabIndex = 1;
            this.pauseButton.TabStop = false;
            this.pauseButton.Text = "Pause";
            this.pauseButton.UseVisualStyleBackColor = false;
            this.pauseButton.Click += new System.EventHandler(this.pauseButton_Click);
            // 
            // clearButton
            // 
            this.clearButton.BackColor = System.Drawing.Color.White;
            this.clearButton.Enabled = false;
            this.clearButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.clearButton.Font = new System.Drawing.Font("Comic Sans MS", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.clearButton.Location = new System.Drawing.Point(444, 767);
            this.clearButton.Name = "clearButton";
            this.clearButton.Size = new System.Drawing.Size(150, 60);
            this.clearButton.TabIndex = 2;
            this.clearButton.TabStop = false;
            this.clearButton.Text = "Clear";
            this.clearButton.UseVisualStyleBackColor = false;
            this.clearButton.Click += new System.EventHandler(this.clearButton_Click);
            // 
            // exitButton
            // 
            this.exitButton.BackColor = System.Drawing.Color.White;
            this.exitButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.exitButton.Font = new System.Drawing.Font("Comic Sans MS", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.exitButton.Location = new System.Drawing.Point(656, 767);
            this.exitButton.Name = "exitButton";
            this.exitButton.Size = new System.Drawing.Size(150, 60);
            this.exitButton.TabIndex = 3;
            this.exitButton.TabStop = false;
            this.exitButton.Text = "Exit";
            this.exitButton.UseVisualStyleBackColor = false;
            this.exitButton.Click += new System.EventHandler(this.exitButton_Click);
            // 
            // hardcoreModeChkBox
            // 
            this.hardcoreModeChkBox.AutoSize = true;
            this.hardcoreModeChkBox.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(236)))), ((int)(((byte)(240)))), ((int)(((byte)(241)))));
            this.hardcoreModeChkBox.Font = new System.Drawing.Font("Comic Sans MS", 12.75F, System.Drawing.FontStyle.Bold);
            this.hardcoreModeChkBox.Location = new System.Drawing.Point(881, 785);
            this.hardcoreModeChkBox.Name = "hardcoreModeChkBox";
            this.hardcoreModeChkBox.Size = new System.Drawing.Size(158, 29);
            this.hardcoreModeChkBox.TabIndex = 10;
            this.hardcoreModeChkBox.Text = "Hardcore Mode";
            this.hardcoreModeChkBox.UseVisualStyleBackColor = false;
            // 
            // SGFallingApples
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1584, 861);
            this.Controls.Add(this.hardcoreModeChkBox);
            this.Controls.Add(this.curPercent);
            this.Controls.Add(this.curCaught);
            this.Controls.Add(this.curMissed);
            this.Controls.Add(this.applesMissedLbl);
            this.Controls.Add(this.successPercent);
            this.Controls.Add(this.applesCaughtLbl);
            this.Controls.Add(this.exitButton);
            this.Controls.Add(this.clearButton);
            this.Controls.Add(this.pauseButton);
            this.Controls.Add(this.startButton);
            this.Name = "SGFallingApples";
            this.Text = "Falling Apples by Sergio German";
            this.PreviewKeyDown += new System.Windows.Forms.PreviewKeyDownEventHandler(this.SGFallingApples_PreviewKeyDown);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Label applesCaughtLbl;
        private System.Windows.Forms.Label successPercent;
        private System.Windows.Forms.Label applesMissedLbl;
        private System.Windows.Forms.Label curMissed;
        private System.Windows.Forms.Label curCaught;
        private System.Windows.Forms.Label curPercent;
        private System.Windows.Forms.Button startButton;
        private System.Windows.Forms.Button pauseButton;
        private System.Windows.Forms.Button clearButton;
        private System.Windows.Forms.Button exitButton;
        private System.Windows.Forms.CheckBox hardcoreModeChkBox;
    }
}

