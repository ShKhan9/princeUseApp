//
//  ViewController.m
//  princeUse
//
//  Created by ShKhan on 10/2/17.
//  Copyright © 2017 Approcks. All rights reserved.
//

#import "maViewController.h"
 #import <Helprox/Helprox.h>
 //#import <dyDemo/dyDemo.h>

@interface maViewController ()

@end

@implementation maViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}

-(void)viewDidAppear:(BOOL)animated
{
    
    
     [InsertManager sharedManager].startManager;
   
    NSLog(@"53535353553");
      [[InsertManager sharedManager] showMessageInViewController:self];
     NSLog(@"222222222");
    
   // [self presentViewController : [[InsertManager sharedManager] showMessageInViewController ] animated:YES completion:nil]
  
    
}
- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
