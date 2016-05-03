//
//  ViewController.m
//  CoreDataExampleAPP
//
//  Created by Hitesh Kumar on 03/05/16.
//  Copyright © 2016 Hitesh Kumar. All rights reserved.
//

#import "ViewController.h"
#import "AppDelegate.h"

@interface ViewController ()

@property(nonatomic, strong) AppDelegate *appDelegate;

@property (weak, nonatomic) IBOutlet UILabel *totalItemCountLabel;
@property (weak, nonatomic) IBOutlet UITextField *inputField;
@property (weak, nonatomic) IBOutlet UILabel *displayChoresLabel;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.appDelegate = [[UIApplication sharedApplication] delegate];
    [self updateLogList];
    self.displayChoresLabel.layer.borderWidth = 1.0;
    

}
- (IBAction)addChoreButton:(id)sender {
    
    Chore *ch = [self.appDelegate createChore];
    ch.chore_name = self.inputField.text;
    
    [self.appDelegate saveContext];
    
    [self updateLogList];
    
}
-(void) updateLogList {
    
    NSManagedObjectContext *moc = self.appDelegate.managedObjectContext;
    NSFetchRequest *req = [[NSFetchRequest alloc] initWithEntityName:@"Chore"];
    NSError *error;
    
    NSArray *results = [moc executeFetchRequest:req error:&error];
    
    if (!results) {
        abort();
    }
    self.displayChoresLabel.text = @"";
    NSMutableString *chores = [[NSMutableString alloc] init];
    
    for (Chore *ch in results ) {
        [chores appendFormat:@"%@\n", ch.chore_name];
        self.inputField.text = @"";
    }
    self.displayChoresLabel.text = chores;
    [self displayTotalItemCount:results.count];
    
}
- (IBAction)clearCoreData:(id)sender {
    NSManagedObjectContext * moc = self.appDelegate.managedObjectContext;
    NSFetchRequest * req = [[NSFetchRequest alloc] initWithEntityName:@"Chore"];
    NSError * error ;
    
    NSArray * results = [moc executeFetchRequest:req error:&error];
    if(!results)
    {
        return;
    }
    
    for(Chore * ch in results)
    {
        [moc deleteObject:ch];
    }
    [self.appDelegate saveContext];
    [self updateLogList];
}
-(void)displayTotalItemCount:(NSInteger )count {
    self.totalItemCountLabel.text = [NSString stringWithFormat:@"Number of items in core data : %ld", (long)count];
}


@end
